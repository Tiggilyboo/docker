# docker
All of my docker environments

## base
Stable debian slim (~55.3MB)

```sh
$ docker run -it tiggilyboo/base /bin/bash
```

## node
Latest stable nodeJs on top of base (+56MB)

```sh
$ docker run -it tiggilyboo/node /bin/bash
$ npm --version
$ node --version
```

## cordova
Latest cordova 7.0.1 on top of node (+65MB)
By default turns off telemetry

```sh
$ docker run -it tiggilyboo/cordova /bin/bash
$ cordova --version
```

## android
Contains OpenJDK 1.8.0_141, Android tools 25.2.5, Gradle 3.3, Android SDK 25 (7.0.1) (+1.03GB)
Symbolic link on `java` to `javac`

```sh
$ docker run -it tiggilyboo/android /bin/bash
$ java -version
$ android list sdk
```

## nativescript
Latest Nativescript on top of android (+130MB)

```sh
$ tns --version
$ tns create chicken
```
