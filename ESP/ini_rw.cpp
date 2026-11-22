// HMOOD__TG@i_8_f
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ini_rw.h"

typedef struct section_t section_t;
typedef struct item_t item_t;

 
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define FREE_SECTION(s) do { if (s) { free((s)->name); free(s); } } while (0)
#define FREE_ITEM(i) do { if (i) { free((i)->name); free((i)->value); free(i); } } while (0)

struct section_t {
    char *name;
    item_t *items;
    item_t *tail;
    section_t *next;
};
struct item_t {
    char *name;
    char *value;
    item_t *next;
};
struct ini {
    char **section_names;
    char **item_names;
    section_t *sections;
    section_t *tail;
    char file[PATH_MAX];
};

static char *safe_strdup(const char *src) {
    if (!src) src = "";
    size_t len = strlen(src);
    char *copy = (char *)malloc(len + 1);
    if (!copy) return NULL;
    memcpy(copy, src, len + 1);
    return copy;
}

static void save_file(INI *ini) {
    if (!ini || ini->file[0] == '\0') return;
    FILE *f = fopen(ini->file, "w");
    if (!f) return;
     
    for (section_t *s = ini->sections; s; s = s->next) {
        if (!s->name) continue;
        fprintf(f, "[%s]\n", s->name);
        for (item_t *i = s->items; i; i = i->next) {
            if (!i->name) continue;
            fprintf(f, "%s = %s\n", i->name, i->value ? i->value : "");
        }
        if (s->next) {
            fputs("\n", f);
        }
    }
    fclose(f);
}


static section_t *find_section(INI *ini, char *name) {
    if (!ini || !ini->sections || !name) {
        return NULL;
    }
    
    section_t *r = NULL;
    for (section_t *s = ini->sections; s; s = s->next) {
        if (s->name && !strcmp(name, s->name)) {
            r = s;
            break;
        }
    }
    return r;
}

static item_t *find_item(section_t *s, char *name) {
    if (!s || !s->items || !name) {
        return NULL;
    }
    
    item_t *r = NULL;
    for (item_t *i = s->items; i; i = i->next) {
        if (i->name && !strcmp(name, i->name)) {
            r = i;
            break;
        }
    }
    return r;
}

static section_t *add_section(INI *ini, char *name) {
    if (!ini) return NULL;
    const char *sec_name = (name && name[0] != '\0') ? name : "Default";

    section_t *s = find_section(ini, (char *)sec_name);
    if (s) {
        return s;
    }
    
    s = (section_t *)malloc(sizeof(section_t));
    if (!s) return NULL;
    s->name = safe_strdup(sec_name);
    if (!s->name) {
        free(s);
        return NULL;
    }
    s->next = NULL;
    s->items = NULL;
    s->tail = NULL;
    
    if (!ini->sections) {
        ini->sections = s;
    } else if (ini->tail) {
        ini->tail->next = s;
    }
    ini->tail = s;
    return ini->tail;
}

static int add_item(INI *ini, char *section, char *item, char *value) {
    if (!ini || !item || item[0] == '\0') return 0;
    const char *val_str = value ? value : "";

    int r = 0;
    section_t *s = add_section(ini, section);
    if (!s) return 0;

    item_t *i = find_item(s, item);
    
    if (!i) {  
        r++;
        i = (item_t *)malloc(sizeof(item_t));
        if (!i) return 0;
        i->name = safe_strdup(item);
        i->value = safe_strdup(val_str);
        if (!i->name || !i->value) {
            FREE_ITEM(i);
            return 0;
        }
        i->next = NULL;
    } else if (!i->value || strcmp(val_str, i->value)) {  
        char *resized = (char *)realloc(i->value, strlen(val_str) + 1);
        if (!resized) return 0;
        i->value = resized;
        strcpy(i->value, val_str);
        save_file(ini);
        return ++r;
    } else {  
        return r;
    }
    
    if (!s->items) {
        r++;
        s->items = i;
    } else if (s->tail) {
        s->tail->next = i;
    }
    s->tail = i;
    
    return r;
}

static int rm_section(INI *ini, section_t *s) {
    if (!ini || !ini->sections || !s) return 0;

    int r = 0;
    while (s->items) {
        r++;
        item_t *i = s->items;
        s->items = i->next;
        FREE_ITEM(i);
    }
    
    if (s == ini->sections) {
        ini->sections = s->next;
        if (!ini->sections) {
            ini->tail = NULL;
        }
        FREE_SECTION(s);
        return ++r;
    }
    
    section_t *s_ = ini->sections;
    while (s_ && s_->next != s) {
        s_ = s_->next;
    }
    if (!s_) {
        FREE_SECTION(s);
        return ++r;
    }

    s_->next = s->next;
    if (!s_->next) {
        ini->tail = s_;
    }
    FREE_SECTION(s);
    return ++r;
}

INI *ini_load(char *path) {
    if (!path || path[0] == '\0') return NULL;

    INI *ini = (INI *)malloc(sizeof(INI));
    if (!ini) return NULL;
    memset(ini, 0, sizeof(INI));

    size_t path_len = strlen(path);
    if (path_len >= PATH_MAX) path_len = PATH_MAX - 1;
    memcpy(ini->file, path, path_len);
    ini->file[path_len] = '\0';

    FILE *f = fopen(ini->file, "r");
    if (!f) {  
        return ini;
    }
    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f);
        return ini;
    }
    long size = ftell(f);
    if (size <= 0 || size > (16 * 1024 * 1024)) {
        fclose(f);
        return ini;
    }
    rewind(f);

    char *data = (char *)malloc((size_t)size + 1);
    if (!data) {
        fclose(f);
        return ini;
    }
    size_t read_bytes = fread(data, 1, (size_t)size, f);
    data[read_bytes] = '\0';
    fclose(f);
    
    char *r = data;
    char *line_end = NULL;
    char *current_section = NULL;
    while ((line_end = strchr(r, '\n')) != NULL) {
        *line_end = '\0';
        char *line = r;
        while (*line == ' ' || *line == '\t' || *line == '\r') {
            line++;
        }

        if (*line == '\0' || *line == ';' || *line == '#') {
            r = line_end + 1;
            continue;
        }

        char *eq_pos = strchr(line, '=');
        if (*line == '[' && (!eq_pos || line < eq_pos)) {
            char *sec_start = line + 1;
            char *sec_end = strchr(sec_start, ']');
            if (sec_end && sec_end > sec_start) {
                size_t sec_len = (size_t)(sec_end - sec_start);
                char *section = (char *)malloc(sec_len + 1);
                if (section) {
                    memcpy(section, sec_start, sec_len);
                    section[sec_len] = '\0';
                    section_t *s = add_section(ini, section);
                    if (s) current_section = s->name;
                    free(section);
                }
            }
        } else if (eq_pos && eq_pos > line) {
            char *item_end = eq_pos;
            while (item_end > line && (item_end[-1] == ' ' || item_end[-1] == '\t' || item_end[-1] == '\r')) {
                item_end--;
            }
            size_t item_len = (size_t)(item_end - line);

            char *val_start = eq_pos + 1;
            while (*val_start == ' ' || *val_start == '\t') {
                val_start++;
            }
            char *val_end = line_end;
            while (val_end > val_start && (val_end[-1] == '\r' || val_end[-1] == ' ' || val_end[-1] == '\t')) {
                val_end--;
            }
            size_t val_len = (size_t)(val_end - val_start);

            if (item_len > 0) {
                char *item = (char *)malloc(item_len + 1);
                char *value = (char *)malloc(val_len + 1);
                if (item && value) {
                    memcpy(item, line, item_len);
                    item[item_len] = '\0';
                    memcpy(value, val_start, val_len);
                    value[val_len] = '\0';
                    add_item(ini, current_section, item, value);
                }
                free(item);
                free(value);
            }
        }
        r = line_end + 1;
    }

    free(data);
    return ini;
}


char *ini_read(INI *ini, char *section, char *item) {
    if (!ini || !section || !item) return NULL;
    section_t *s;
    item_t *i;
    if (!(s = find_section(ini, section)) || !(i = find_item(s, item))) {
        return NULL;
    }
    
    return i->value;
}

int ini_write(INI *ini, char *section, char *item, char *value) {
    if (!ini || !item) return 0;
    int r = add_item(ini, section, item, value);
    if (r) {
        save_file(ini);
    }
    return r;
}

int ini_remove(INI *ini, char *section, char *item) {
    if (!ini || !section) return 0;
    section_t *s;
    item_t *i = nullptr;
    
    if (!(s = find_section(ini, section)) || (item && !(i = find_item(s, item)))) {
        return 0;
    }
    
    if (!item || !s->items || !s->items->next) {
        int r = rm_section(ini, s);
        save_file(ini);
        return r;
    }
    
    if (i == s->items) {
        s->items = i->next;
        FREE_ITEM(i);
        save_file(ini);
        return 1;
    }
    
    item_t *i_ = s->items;
    while (i_ && i_->next != i) {
        i_ = i_->next;
    }
    if (!i_) return 0;

    i_->next = i->next;
    if (!i_->next) {
        s->tail = i_;
    }
    FREE_ITEM(i);
    save_file(ini);
    return 1;
}


int configManager::readInteger(INI* config,const char *section, const char *key, int deValue) {
    if (!config || !section || !key) return deValue;
    char *result = ini_read(config, (char*)section, (char*)key);
    if (result == NULL) {
        return deValue;
    }
    return atoi(result);
}

float configManager::readFloat(INI* config,const char *section, const char *key, float deValue) {
    if (!config || !section || !key) return deValue;
    char *result = ini_read(config, (char*)section, (char*)key);
    if (result == NULL) {
        return deValue;
    }
    return (float)atof(result);
}

bool configManager::readBoolean(INI* config,const char *section, const char *key, bool deValue) {
    if (!config || !section || !key) return deValue;
    char *result = ini_read(config, (char*)section, (char*)key);
    if (result == NULL) {
        return deValue;
    }
    return atoi(result) != 0;
}


void configManager::putInteger(INI* config,const char *section, const char *key, int value) {
    if (!config || !section || !key) return;
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", value);
    ini_write(config, (char*)section, (char*)key, buffer);
}

void configManager::putFloat(INI* config,const char *section, const char *key, float value) {
    if (!config || !section || !key) return;
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "%f", value);
    ini_write(config, (char*)section, (char*)key, buffer);
}

void configManager::putBoolean(INI* config,const char *section, const char *key, bool value) {
    if (!config || !section || !key) return;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", value ? 1 : 0);
    ini_write(config, (char*)section, (char*)key, buffer);
}
