FROM php:8.2-apache

# Apache mod_rewrite aktivləşdir (lazım olsa)
RUN a2enmod rewrite

# Port ayarını Render-in PORT dəyişəninə uyğunlaşdır
RUN sed -i 's/Listen 80/Listen 8080/' /etc/apache2/ports.conf \
    && sed -i 's/:80/:8080/' /etc/apache2/sites-available/000-default.conf

WORKDIR /var/www/html

# Layihə fayllarını kopyala (index.html, backend.php və s.)
COPY . /var/www/html/

# Yazma/icazə hüquqlarını tənzimlə
RUN chown -R www-data:www-data /var/www/html \
    && chmod -R 755 /var/www/html

EXPOSE 8080

CMD ["apache2-foreground"]
