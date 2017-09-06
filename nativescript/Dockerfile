FROM tiggilyboo/android
LABEL description="NativeScript"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV DEBIAN_FRONTEND=noninteractive \
  ANDROID_HOME=/usr/local/android-sdk-linux \
  JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64 \
  JAVA_TOOL_OPTIONS="-Dfile.encoding=UTF8" \
  BUILD_PACKAGES="lib32z1 lib32ncurses5 lib32stdc++6 g++"

RUN apt-get update && \
  apt-get install --no-install-recommends -yq $BUILD_PACKAGES && \
  npm install nativescript -g --unsafe-perm && \
  apt-get remove --allow-remove-essential --purge -y $BUILD_PACKAGES && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

CMD ["/bin/bash"]
