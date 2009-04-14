#!/bin/sh

CONFIG_SHELL=/bin/sh
export CONFIG_SHELL
PREFIX=/usr/i586-mingw32msvc
TARGET=i586-mingw32msvc
PATH="$PREFIX/bin:$PREFIX/$TARGET/bin:$PATH"
export PATH
cache=cross-config.cache
sh configure --cache-file="$cache" --prefix=$PREFIX \
	--target=$TARGET --host=$TARGET --build=i386-linux \
	$*
status=$?
rm -f "$cache"
exit $status
