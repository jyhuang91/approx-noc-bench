#!/bin/sh

PREFIX=${PWD}/..

../src/configure --prefix=$PREFIX --enable-threads --enable-zsim-hooks
