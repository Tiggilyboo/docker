FROM tiggilyboo/cordova
LABEL description="Java 8, Android SDK"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV DEBIAN_FRONTEND=noninteractive \
    INIT_PACKAGES="curl unzip" \
    BUILD_PACKAGES="default-jre" \
    JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64 \
    JAVA_TOOL_OPTIONS="-Dfile.encoding=UTF8" \
    ANDROID_VERSION=25.2.5 \
    ANDROID_HOME=/usr/local/android-sdk-linux \
    GRADLE_VERSION=3.3 \
    GRADLE_HOME=/src/gradle

ENV PATH=$PATH:$GRADLE_HOME/bin:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools

RUN \
  mkdir -p /usr/share/man/man1 && \
  apt-get update && apt-get install --no-install-recommends -y $INIT_PACKAGES $BUILD_PACKAGES && \
  curl -o ~/asdk.zip https://dl.google.com/android/repository/tools_r${ANDROID_VERSION}-linux.zip && \
  curl -o ~/gradle.zip https://downloads.gradle.org/distributions/gradle-${GRADLE_VERSION}-all.zip && \
  unzip -q -d $ANDROID_HOME/ ~/asdk.zip && \
  unzip -q -d $GRADLE_HOME/ ~/gradle.zip && \
  rm -f ~/*.zip && \
  ( sleep 5 && while [ 1 ]; do sleep 1; echo y; done ) | $ANDROID_HOME/tools/android update sdk --no-ui -a --filter platform-tool,build-tools-26.0.1,android-25 && \
  apt-get remove --allow-remove-essential --purge -y $INIT_PACKAGES && \
  apt-get autoremove -y && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

VOLUME /src
WORKDIR /src

RUN ln -s /src/.debug.keystore /root/.android/.debug.keystore && \
  ln -s /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java /usr/bin/javac
