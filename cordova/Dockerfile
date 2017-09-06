FROM tiggilyboo/node
LABEL description="Apache Cordova"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV CORDOVA_VERSION=7.0.1
WORKDIR /tmp

RUN npm i -g --unsafe-perm cordova@${CORDOVA_VERSION} && \
    cordova telemetry off
