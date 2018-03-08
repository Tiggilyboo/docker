FROM tiggilyboo/ionic
LABEL description="Oracle Java 8, Android SDK"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV DEBIAN_FRONTEND=noninteractive \
    INIT_PACKAGES="curl unzip ca-certificates python" \
    BUILD_PACKAGES="" \
    JAVA_FILE=jdk-8u161-linux-x64.tar.gz \
		JAVA_ROOT=/srv/java \ 
    JAVA_TOOL_OPTIONS="-Dfile.encoding=UTF8" \
    ANDROID_VERSION=25.2.5 \
    ANDROID_HOME=/usr/local/android-sdk-linux \
    ANDROID_PACKAGES="tools;android-26,platform-tools;android-26,build-tools;android-26,android-26,extra" \
    GRADLE_VERSION=3.3 \
    GRADLE_HOME=/srv/gradle

ENV JAVA_HOME=$JAVA_ROOT \
		PATH=$PATH:$JAVA_ROOT/bin:$GRADLE_HOME/gradle-$GRADLE_VERSION/bin:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools

RUN \
  apt-get update && apt-get install --no-install-recommends -y $INIT_PACKAGES $BUILD_PACKAGES && \
  curl -C - -L -O -# -H "Cookie: oraclelicense=accept-securebackup-cookie" "http://download.oracle.com/otn-pub/java/jdk/8u161-b12/2f38c3b165be4555a1fa6e98c45e0808/$JAVA_FILE" && \
  mkdir -p /srv/java && \
  tar xzf $JAVA_FILE -C $JAVA_ROOT --strip-components=1 && \
  rm -f $JAVA_FILE && \
	mkdir -p /usr/share/man/man1 && \
  curl -o ~/asdk.zip https://dl.google.com/android/repository/tools_r${ANDROID_VERSION}-linux.zip && \
  curl -o ~/gradle.zip https://downloads.gradle.org/distributions/gradle-${GRADLE_VERSION}-all.zip && \
  unzip -q -d $ANDROID_HOME/ ~/asdk.zip && \
  unzip -q -d $GRADLE_HOME/ ~/gradle.zip && \
  rm -f ~/*.zip && \
	chown -R root $ANDROID_HOME && \
  ( sleep 8 && while [ 1 ]; do sleep 1; echo y; done ) | \
    $ANDROID_HOME/tools/android --clear-cache update sdk --no-ui -a --filter $ANDROID_PACKAGES && \
  apt-get remove --allow-remove-essential --purge -y $INIT_PACKAGES && \
  apt-get autoremove -y && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt && \
	rm -rf $ANDROID_HOME/temp/* && \
  ln -s /src/.debug.keystore /root/.android/.debug.keystore

VOLUME /src
WORKDIR /src

