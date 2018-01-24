#!/bin/bash
mkdir -p /config

echo "\
admin.themoonunit.com {\n\
  proxy / $POD_IP:80 {\n\
    transparent\n\
  }\n\
  gzip
  tls slartibartfast@themoonunit\n\
}" >> /config/Caddyfile

caddy -quic --conf /config/Caddyfile --log stdout
