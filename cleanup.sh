#!/bin/bash
docker stop -f $(docker ps -a -q)
docker rm -f $(docker ps -a -q)
docker volume rm -f  $(docker volume ls -f dangling=true -q)
docker rmi -f $(docker images -f dangling=true -q)
