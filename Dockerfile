FROM php:8.2-apache

# Apache mod_rewrite aktivləşdir
RUN a2enmod rewrite

# Render-in standart 8080 portu üçün Apache konfiqurasiyasını yenilə
RUN sed -i 's/Listen 80/Listen 8080/' /etc/apache2/ports.conf \
    && sed -i 's/:80/:8080/' /etc/apache2/sites-available/000-default.conf

# İş qovluğu
WORKDIR /var/www/html

# Repozitoriyadakı bütün faylları (KeyPanel.php, backend.php və s.) kopyala
COPY . /var/www/html/

# darkos_data.json yaradıla və yenilənə bilməsi üçün icazələri ver
RUN touch /var/www/html/darkos_data.json \
    && chown -R www-data:www-data /var/www/html \
    && chmod -R 777 /var/www/html

EXPOSE 8080

CMD ["apache2-foreground"]
