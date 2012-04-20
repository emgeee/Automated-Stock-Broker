#############################################################################
# Makefile for building: Market
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Apr 20 14:29:50 2012
# Project:  Market.pro
# Template: subdirs
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Market.pro
#############################################################################

first: make_default
MAKEFILE      = Makefile
QMAKE         = /usr/bin/qmake-qt4
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		sub-MarketSimulation \
		sub-StockBroker

MarketSimulation//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) MarketSimulation/ || $(MKDIR) MarketSimulation/ 
	cd MarketSimulation/ && $(QMAKE) /home/mgreen/Automated-Stock-Broker/MarketSimulation/MarketSimulation.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-MarketSimulation-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) MarketSimulation/ || $(MKDIR) MarketSimulation/ 
	cd MarketSimulation/ && $(QMAKE) /home/mgreen/Automated-Stock-Broker/MarketSimulation/MarketSimulation.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-MarketSimulation: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE)
sub-MarketSimulation-make_default: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) 
sub-MarketSimulation-make_first: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) first
sub-MarketSimulation-all: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) all
sub-MarketSimulation-clean: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) clean
sub-MarketSimulation-distclean: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) distclean
sub-MarketSimulation-install_subtargets: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) install
sub-MarketSimulation-uninstall_subtargets: MarketSimulation//$(MAKEFILE) FORCE
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) uninstall
StockBroker//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) StockBroker/ || $(MKDIR) StockBroker/ 
	cd StockBroker/ && $(QMAKE) /home/mgreen/Automated-Stock-Broker/StockBroker/StockBroker.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-StockBroker-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) StockBroker/ || $(MKDIR) StockBroker/ 
	cd StockBroker/ && $(QMAKE) /home/mgreen/Automated-Stock-Broker/StockBroker/StockBroker.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-StockBroker: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE)
sub-StockBroker-make_default: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) 
sub-StockBroker-make_first: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) first
sub-StockBroker-all: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) all
sub-StockBroker-clean: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) clean
sub-StockBroker-distclean: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) distclean
sub-StockBroker-install_subtargets: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) install
sub-StockBroker-uninstall_subtargets: StockBroker//$(MAKEFILE) FORCE
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) uninstall

Makefile: Market.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Market.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Market.pro

qmake_all: sub-MarketSimulation-qmake_all sub-StockBroker-qmake_all FORCE

make_default: sub-MarketSimulation-make_default sub-StockBroker-make_default FORCE
make_first: sub-MarketSimulation-make_first sub-StockBroker-make_first FORCE
all: sub-MarketSimulation-all sub-StockBroker-all FORCE
clean: sub-MarketSimulation-clean sub-StockBroker-clean FORCE
distclean: sub-MarketSimulation-distclean sub-StockBroker-distclean FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-MarketSimulation-install_subtargets sub-StockBroker-install_subtargets FORCE
uninstall_subtargets: sub-MarketSimulation-uninstall_subtargets sub-StockBroker-uninstall_subtargets FORCE

sub-MarketSimulation-check: MarketSimulation/$(MAKEFILE)
	cd MarketSimulation/ && $(MAKE) -f $(MAKEFILE) check
sub-StockBroker-check: StockBroker/$(MAKEFILE)
	cd StockBroker/ && $(MAKE) -f $(MAKEFILE) check
check: sub-MarketSimulation-check sub-StockBroker-check

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:
