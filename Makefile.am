AM_CPPFLAGS =								          \
  -I m4 ${ACLOCAL_FLAGS}               \
	-I$(top_srcdir)							        \
	-I$(srcdir)							            \
	$(TEST_CFLAGS)						            \
	-DDATADIR=\""$(datadir)"\"					\
	-DLIBDIR=\""$(libdir)"\"

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = 			\
	BUGS			\
	HACKING			\
	MAINTAINERS \
  gtk-doc.make\
  $(NULL)


MAINTAINERCLEANFILES = 		\
	$(GITIGNORE_MAINTAINERCLEANFILES_TOPLEVEL) \
	$(GITIGNORE_MAINTAINERCLEANFILES_MAKEFILE_IN) \
	$(GITIGNORE_MAINTAINERCLEANFILES_M4_LIBTOOL) \
	ABOUT-NLS		\
	INSTALL			\
	config.rpath		\
	gtk-doc.make		\
	py-compile		\
	test-driver		\
	m4/gnome-doc-utils.m4	\
	m4/gtk-doc.m4		\
	m4/intltool.m4		\
	m4/codeset.m4		\
	m4/fcntl-o.m4		\
	m4/gettext.m4		\
	m4/glibc2.m4		\
	m4/glibc21.m4		\
	m4/iconv.m4		\
	m4/intdiv0.m4		\
	m4/intl.m4		\
	m4/intldir.m4		\
	m4/intlmacosx.m4	\
	m4/intmax.m4		\
	m4/inttypes-pri.m4	\
	m4/inttypes_h.m4	\
	m4/lcmessage.m4		\
	m4/lib-ld.m4		\
	m4/lib-link.m4		\
	m4/lib-prefix.m4	\
	m4/lock.m4		\
	m4/longlong.m4		\
	m4/nls.m4		\
	m4/po.m4		\
	m4/printf-posix.m4	\
	m4/progtest.m4		\
	m4/size_max.m4		\
	m4/stdint_h.m4		\
	m4/threadlib.m4		\
	m4/uintmax_t.m4		\
	m4/visibility.m4	\
	m4/wchar_t.m4		\
	m4/wint_t.m4		\
	m4/xsize.m4		\
	po/Makevars.template	\
	po/Rules-quot		\
	po/*.sed		\
	po/*.header		\
	po/*.sin

INST_H_FILES              =
noinst_LTLIBRARIES        =
noinst_PROGRAMS	          =
bin_PROGRAMS              = testbin
pkglib_LTLIBRARIES        =
CLEANFILES                =
DISTCLEANFILES            =
BUILT_SOURCES             =




testbin_common_cppflags =         \
  -I$(top_srcdir)                 \
  -I$(top_srcdir)                 \
  -I$(top_builddir)               \
  -DDATADIR=\""$(datadir)"\"      \
  -DLIBDIR=\""$(libdir)"\"

testbin_common_cflags =           \
  $(TEST_CFLAGS)                         \
  $(WARN_CFLAGS)                        \
  $(DISABLE_DEPRECATED_CFLAGS)

testbin_CPPFLAGS = $(testbin_common_cppflags)
testbin_CFLAGS = $(testbin_common_cflags)

testbin_SOURCES =					 \
                  main.c         \
                  test-resources.h                  \
                  test-resources.c                  \
                	$(INST_H_FILES)

#that effort just for a simple html-source
lib_resource_deps = $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies --sourcedir $(srcdir) --sourcedir $(builddir) $(builddir)/test.gresource.xml)

test_resources_c_deps = $(builddir)/test.gresource.xml $(lib_resource_deps)

test-resources.h: $(test_resources_deps)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES)\
		--target="$@"\
		--sourcedir="$(srcdir)"\
		--sourcedir="$(builddir)"\
		--generate-header "$(builddir)/test.gresource.xml"

test-resources.c: $(test_resources_c_deps)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES)\
		--target="$@"\
		--sourcedir="$(srcdir)"\
		--sourcedir="$(builddir)"\
		--generate-source "$(builddir)/test.gresource.xml"

EXTRA_DIST +=                             \
	test.gresource.xml.in             \
	$(test_resource_deps)                    

BUILT_SOURCES +=                         \
	$(testbin_sources)               \
	test-resources.c                 \
	test-resources.h                 \
	test.gresource.xml

#If possible write own exportable library with libtool
testbin_LDADD = $(TEST_LIBS)

testbin_datadir = $(datarootdir)/graphes
testbin_data_DATA = flotr2_example.htm

CLEANFILES += $(BUILT_SOURCES)

