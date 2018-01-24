# docker
All of my docker environments.  

## base
Stable debian slim (~55.3MB)

```sh
$ docker run -it tiggilyboo/base /bin/bash
```

Having issues cloning large git repos? You can increase your docker environments network adapter MTU by changing your docker daemon's parameters. `vim /lib/systemd/system/docker.service`, and adding the following:

```diff
...
- ExecStart=/usr/bin/dockerd -H fd://
+ ExecStart=/usr/bin/dockerd -H fd:// --mtu=1400
...
```

---

## android
Contains OpenJDK 1.8.0_141, Android tools 25.2.5, Gradle 3.3, Android SDK 26 (8.0.0)

Symbolic link on `java` to `javac`

```sh
$ docker run -it tiggilyboo/android /bin/bash
$ java -version
$ android list sdk
```

## cordova
Latest cordova 7.0.1 on top of node (+65MB)

By default turns off telemetry

```sh
$ docker run -it tiggilyboo/cordova /bin/bash
$ cordova --version
```

## db
Postgres 1.10 image on top of base (+226MB)

```sh
$ docker run -d tiggilyboo/db -e POSTGRES_DB="postgres" -e POSTGRES_USER="postgres" -e POSTGRES_PASSWORD="postgres" -p 5432:5432 -v ./data:/var/lib/postgresql/db-data
$ psql -U postgres -h 127.0.0.1 --password postgres -p 5432
```

## go
Golang 1.9 on top of base (+527.4MB)

```sh
$ docker run -it tiggilyboo/go /bin/bash
$ go version
```

## https
Let's Encrypt Image on top of base, using kube-https (+102MB)
See documentation [here](https://github.com/jetstack/kube-lego)

```sh
$ docker run -it tiggilyboo/https /bin/bash
```

## ionic
Ionic Framework 3.0.19 on top of android (+100MB)

```sh
$ docker run -it tiggilyboo/ionic -v ./app:/src -p 8100 -p 35729 -p 53703 /bin/bash
$ ionic cordova run android -lc
```

## mysql
MySQL 15.1 on top of base (+243MB)

```sh
$ docker run -it tiggilyboo/mysql -e MYSQL_USER="root" -e MYSQL_DATABASE="db" -e MYSQL_PASSWORD="password" /bin/bash
$ mysql --version
```

## nativescript
Nativescript on top of android (+130MB)

```sh
$ tns --version
$ tns create chicken
```

## node
Latest stable nodeJs on top of base (+56MB)

```sh
$ docker run -it tiggilyboo/node /bin/bash
$ npm --version
$ node --version
```

## php
PHP 7.0.19 on top of base (+132MB)

```sh
$ docker run -it tiggilyboo/php /bin/bash
$ php --version
```

## qt
Golang Qt5 on top of go (+2.9GB)

```sh
$ docker run -it tiggilyboo/qt /bin/bash
```

## reactnative
ReactNative CLI, native app with watchman and inotify-tools 

```sh
$ docker run -it tiggilyboo/reactnative /bin/bash
```
