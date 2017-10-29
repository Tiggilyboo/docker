FROM tiggilyboo/cordova
LABEL description="Oracle Java 8, Android SDK"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV DEBIAN_FRONTEND=noninteractive \
    INIT_PACKAGES="curl unzip ca-certificates" \
    BUILD_PACKAGES="" \
    JAVA_ROOT=/srv/java \ 
    JAVA_TOOL_OPTIONS="-Dfile.encoding=UTF8" \
    ANDROID_VERSION=25.2.5 \
    ANDROID_HOME=/usr/local/android-sdk-linux \
    ANDROID_PACKAGES="tools,platform-tools,build-tools-26.0.1,android-25,extra" \
    GRADLE_VERSION=3.3 \
    GRADLE_HOME=/srv/gradle

ENV JAVA_HOME=$JAVA_ROOT \
		PATH=$PATH:$JAVA_ROOT/jdk/bin:$JAVA_ROOT:$GRADLE_HOME/bin:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools

RUN \
  apt-get update && apt-get install --no-install-recommends -y $INIT_PACKAGES $BUILD_PACKAGES && \
  curl -C - -L -O -# -H "Cookie: oraclelicense=accept-securebackup-cookie" "http://download.oracle.com/otn-pub/java/jdk/8u144-b01/090f390dda5b47b9b721c7dfaa008135/jdk-8u144-linux-x64.tar.gz" && \
  mkdir -p /srv/java && \
  tar xzf jdk-8u144-linux-x64.tar.gz -C $JAVA_ROOT --strip-components=1 && \
  rm -f jdk-8u112-linux-x64.tar.gz && \
  ln -s $JAVA_ROOT/bin/java /usr/bin/java && \
  ln -s $JAVA_ROOT/bin/java /usr/bin/javac && \
	mkdir -p /usr/share/man/man1 && \
  curl -o ~/asdk.zip https://dl.google.com/android/repository/tools_r${ANDROID_VERSION}-linux.zip && \
  curl -o ~/gradle.zip https://downloads.gradle.org/distributions/gradle-${GRADLE_VERSION}-all.zip && \
  unzip -q -d $ANDROID_HOME/ ~/asdk.zip && \
  unzip -q -d $GRADLE_HOME/ ~/gradle.zip && \
  rm -f ~/*.zip && \
  ( sleep 5 && while [ 1 ]; do sleep 1; echo y; done ) | \
    $ANDROID_HOME/tools/android update sdk --no-ui -a --filter $ANDROID_PACKAGES && \
  apt-get remove --allow-remove-essential --purge -y $INIT_PACKAGES && \
  apt-get autoremove -y && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt && \
  ln -s /src/.debug.keystore /root/.android/.debug.keystore

VOLUME /src
WORKDIR /src

