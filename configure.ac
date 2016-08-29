#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])

m4_define(test_major_version, 0)
m4_define(test_minor_version, 0)
m4_define(test_micro_version, 1)
m4_define(test_version, test_major_version.test_minor_version.test_micro_version)

AC_INIT([test], [test_version], [schmidt.emanuel@uni-jena.de],[test],[ifk.uni.jena.de/libs/test])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR(main.c)
AC_CONFIG_MACRO_DIR([m4])

# define auxiliary directory
AC_CONFIG_AUX_DIR([aux-build])

# Save this value here, since automake will set cflags later
cflags_set=${CFLAGS:+set}

AM_INIT_AUTOMAKE([1.11 -Wno-portability no-define no-dist-gzip dist-xz tar-ustar subdir-objects foreign])
AM_MAINTAINER_MODE([enable])

# check for programs
AC_PROG_CC
AM_PROG_CC_STDC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_SYS_LARGEFILE
PKG_PROG_PKG_CONFIG

# start libtool
LT_PREREQ([2.2.6])
LT_INIT(disable-static)

AC_CHECK_FUNC(sigaction)
AC_CHECK_LIB(m, floor)

AC_HEADER_STDC

# start libtool
LT_PREREQ([2.2.6])
LT_INIT([disable-static])

dnl make sure we keep ACLOCAL_FLAGS around for maintainer builds to work
AC_SUBST(ACLOCAL_AMFLAGS, "$ACLOCAL_FLAGS -I m4")

dnl location to install runtime libraries, e.g. ../../lib to install
dnl to /lib if libdir is /usr/lib
AC_ARG_WITH(runtime-libdir,
           [AS_HELP_STRING([--with-runtime-libdir=RELPATH],
                           [install runtime libraries relative to libdir])],
           [],
	   [with_runtime_libdir=""])
TEST_RUNTIME_LIBDIR="$with_runtime_libdir"
ABS_TEST_RUNTIME_LIBDIR="`readlink -f $libdir/$with_runtime_libdir`"
AC_SUBST(TEST_RUNTIME_LIBDIR)
AC_SUBST(ABS_TEST_RUNTIME_LIBDIR)
AM_CONDITIONAL(HAVE_TEST_RUNTIME_LIBDIR, [test "x$with_runtime_libdir" != "x"])

dnl Start of pkg-config checks
PKG_PROG_PKG_CONFIG(0.16)

# Dependencies
PKG_CHECK_MODULES(TEST, [
	glib-2.0 >= 2.37.5
	gio-2.0 >= 2.37.0
	gtk+-3.0 >= 3.9.9
	webkit2gtk-4.0
])

TEST_CFLAGS="$TEST_CFLAGS $X11_CFLAGS $UNIX_CFLAGS"
TEST_LIBS="$TEST_LIBS $X11_LIBS $UNIX_LIBS"

AC_SUBST(TEST_CFLAGS)
AC_SUBST(TEST_LIBS)
AC_SUBST(BIN_TEST_LIBS)
AC_SUBST(BIN_TEST_LDFLAGS)
AC_SUBST(BIN_TEST_CFLAGS)

AC_PATH_PROG(GLIB_COMPILE_RESOURCES, glib-compile-resources)

AC_ARG_ENABLE(deprecations,
              [AS_HELP_STRING([--enable-deprecations],
              [warn about deprecated usages [default=yes]])],
              [enable_deprecations=$enableval], [])

AC_MSG_CHECKING([whether to forbid deprecated symbols])
if test "$enable_deprecations" = "yes"; then
	AC_MSG_RESULT(yes)
	DISABLE_DEPRECATED_CFLAGS="\
  -DGSEAL_ENABLE \
  -DG_DISABLE_DEPRECATED \
  -DGDK_DISABLE_DEPRECATED \
  -DGTK_DISABLE_DEPRECATED \
  -DGDK_PIXBUF_DISABLE_DEPRECATED \
  -DGNOME_DISABLE_DEPRECATED \
  -DPEAS_DISABLE_DEPRECATED"

	AC_SUBST(DISABLE_DEPRECATED_CFLAGS)
else
	AC_MSG_RESULT(no)
fi

AC_CONFIG_FILES([
Makefile
test.gresource.xml
])

if test "$platform_win32" = yes; then
	TEST_IMPLIB='-L${libdir}/test -ltest'
	PLUGIN_LIBTOOL_FLAGS="-module -avoid-version -no-undefined"
	if test "$os_win32" = yes; then
		PLUGIN_LIBTOOL_FLAGS="${PLUGIN_LIBTOOL_FLAGS} -mwindows"
	fi
else
	TEST_IMPLIB=""
	PLUGIN_LIBTOOL_FLAGS="-module -avoid-version"
fi
AC_SUBST(TEST_IMPLIB)
AC_SUBST(PLUGIN_LIBTOOL_FLAGS)

AC_OUTPUT

