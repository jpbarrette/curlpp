#!/bin/sh

die(){
	echo "$@"
	exit
}

# this works as 'which' but we use a different name to make it more obvious we
# aren't using 'which'! ;-)
findtool(){
  file="$1"

  IFS=":"
  for path in $PATH
  do
    if test -r "$path/$file"; then
      echo "$path/$file"
      return
    fi
  done
}

#--------------------------------------------------------------------------
# autoconf 2.57 or newer
#
need_autoconf="2.57"
ac_version=`${AUTOCONF:-autoconf} --version 2>/dev/null|head -1| sed -e 's/^[^0-9]*//' -e 's/[a-z]* *$//'`
if test -z "$ac_version"; then
  echo "buildconf: autoconf not found."
  echo "            You need autoconf version $need_autoconf or newer installed."
  exit 1
fi
IFS=.; set $ac_version; IFS=' '
if test "$1" = "2" -a "$2" -lt "57" || test "$1" -lt "2"; then
  echo "buildconf: autoconf version $ac_version found."
  echo "            You need autoconf version $need_autoconf or newer installed."
  echo "            If you have a sufficient autoconf installed, but it"
  echo "            is not named 'autoconf', then try setting the"
  echo "            AUTOCONF environment variable."
  exit 1
fi

echo "buildconf: autoconf version $ac_version (ok)"

#--------------------------------------------------------------------------
# autoheader 2.50 or newer
#
ah_version=`${AUTOHEADER:-autoheader} --version 2>/dev/null|head -1| sed -e 's/^[^0-9]*//' -e 's/[a-z]* *$//'`
if test -z "$ah_version"; then
  echo "buildconf: autoheader not found."
  echo "            You need autoheader version 2.50 or newer installed."
  exit 1
fi
IFS=.; set $ah_version; IFS=' '
if test "$1" = "2" -a "$2" -lt "50" || test "$1" -lt "2"; then
  echo "buildconf: autoheader version $ah_version found."
  echo "            You need autoheader version 2.50 or newer installed."
  echo "            If you have a sufficient autoheader installed, but it"
  echo "            is not named 'autoheader', then try setting the"
  echo "            AUTOHEADER environment variable."
  exit 1
fi

echo "buildconf: autoheader version $ah_version (ok)"

#--------------------------------------------------------------------------
# automake 1.9 or newer
#
need_automake="1.9"
am_version=`${AUTOMAKE:-automake} --version 2>/dev/null|head -1| sed -e 's/^.* \([0-9]\)/\1/' -e 's/[a-z]* *$//' -e 's/\(.*\)\(-p.*\)/\1/'`
if test -z "$am_version"; then
  echo "buildconf: automake not found."
  echo "            You need automake version $need_automake or newer installed."
  exit 1
fi
IFS=.; set $am_version; IFS=' '
if test "$1" = "1" -a "$2" -lt "9" || test "$1" -lt "1"; then
  echo "buildconf: automake version $am_version found."
  echo "            You need automake version $need_automake or newer installed."
  echo "            If you have a sufficient automake installed, but it"
  echo "            is not named 'automake', then try setting the"
  echo "            AUTOMAKE environment variable."
  exit 1
fi

echo "buildconf: automake version $am_version (ok)"


#--------------------------------------------------------------------------
# libtool check
#
LIBTOOL_WANTED_MAJOR=1
LIBTOOL_WANTED_MINOR=4
LIBTOOL_WANTED_PATCH=2
LIBTOOL_WANTED_VERSION=1.4.2

# this approach that tries 'glibtool' first is some kind of work-around for
# some BSD-systems I believe that use to provide the GNU libtool named
# glibtool, with 'libtool' being something completely different.
libtool=`findtool glibtool 2>/dev/null`
if test ! -x "$libtool"; then
  libtool=`findtool libtool`
fi

LIBTOOLIZE="${libtool}ize"

lt_pversion=`$libtool --version 2>/dev/null|head -1|sed -e 's/^[^0-9]*//g' -e 's/[- ].*//'`
if test -z "$lt_pversion"; then
  echo "buildconf: libtool not found."
  echo "            You need libtool version $LIBTOOL_WANTED_VERSION or newer installed"
  exit 1
fi
lt_version=`echo $lt_pversion|sed -e 's/\([a-z]*\)$//'`
IFS=.; set $lt_version; IFS=' '
lt_status="good"

major=$1
minor=$2
patch=$3

if test "$major" = "$LIBTOOL_WANTED_MAJOR"; then
   if test "$minor" -lt "$LIBTOOL_WANTED_MINOR"; then
      lt_status="bad"
   elif test -n "$LIBTOOL_WANTED_PATCH"; then
       if test "$minor" -gt "$LIBTOOL_WANTED_MINOR"; then
         lt_status="good"
       elif test -n "$patch"; then
          if test "$patch" -lt "$LIBTOOL_WANTED_PATCH"; then
             lt_status="bad"
          fi
       else
          lt_status="bad"
       fi
   fi
fi
if test $lt_status != "good"; then
  echo "buildconf: libtool version $lt_pversion found."
  echo "            You need libtool version $LIBTOOL_WANTED_VERSION or newer installed"
  exit 1
fi

echo "buildconf: libtool version $lt_version (ok)"

#--------------------------------------------------------------------------
# m4 check
#
m4=`${M4:-m4} --version 2>/dev/null|head -1`;
m4_version=`echo $m4 | sed -e 's/^.* \([0-9]\)/\1/' -e 's/[a-z]* *$//'`

if { echo $m4 | grep "GNU" >/dev/null 2>&1; } then
  echo "buildconf: GNU m4 version $m4_version (ok)"
else
  echo "buildconf: m4 version $m4 found. You need a GNU m4 installed!"
  exit 1
fi


# ------------------------------------------------------------

# run the correct scripts now
aclocalinclude="-I m4 $ACLOCAL_FLAGS"

echo "buildconf: running libtoolize"
${LIBTOOLIZE:-libtoolize} --copy --automake --force || die "The libtool command failed"
echo "buildconf: running aclocal"
${ACLOCAL:-aclocal} $ACLOCAL_FLAGS $aclocalinclude || die "The aclocal command line failed"
echo "buildconf: running aclocal hack to convert all mv to mv -f"
perl -i.bak -pe 's/\bmv +([^-\s])/mv -f $1/g' aclocal.m4
echo "buildconf: running autoconf"
${AUTOCONF:-autoconf}     || die "The command '${AUTOCONF:-autoconf}' failed"
echo "buildconf: running autoheader"
${AUTOHEADER:-autoheader} || die "The autoheader command failed"
echo "buildconf: running automake"
${AUTOMAKE:-automake} -a  || die "The automake command failed"

echo "buildconf: OK"
exit 0
