NULL =

sounddir = $(datadir)/sounds/ukui/default/alerts

sound_DATA =			\
	bark.ogg		\
	drip.ogg		\
	glass.ogg		\
	sonar.ogg		\
	$(NULL)

metadata_in_files = ukui-sounds-default.xml.in
metadatadir = $(pkgdatadir)/sounds
metadata_DATA = $(metadata_in_files:.xml.in=.xml)
@INTLTOOL_XML_RULE@

noinst_DATA = ukui-sounds-default.xml.in
CLEANFILES = ukui-sounds-default.xml ukui-sounds-default.xml.in

EXTRA_DIST = $(sound_DATA) ukui-sounds-default.xml.in.in

ukui-sounds-default.xml.in: ukui-sounds-default.xml.in.in Makefile
	$(AM_V_GEN)sed -e 's^\@datadir\@^$(datadir)^g' < $(srcdir)/ukui-sounds-default.xml.in.in > ukui-sounds-default.xml.in.tmp \
	&& mv ukui-sounds-default.xml.in.tmp ukui-sounds-default.xml.in

MAINTAINERCLEANFILES = \
	Makefile.in

-include $(top_srcdir)/git.mk
