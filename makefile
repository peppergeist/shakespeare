CC          := clang++
TARGET      := shakespeare-quote
SRCDIR      := src
INCDIR      := inc
BUILDDIR    := obj
TARGETDIR   := bin
DATDIR      := dat
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o
CFLAGS      := -Wall -O3 -g
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
INSTALLBIN  := /usr/local/bin
INSTALLDIR  := /usr/local/opt

# default make
all: $(TARGET)

# remake
remake: cleaner all

# make directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

# clean objects
clean:
	@$(RM) -rf $(BUILDDIR)

# clean all
cleaner: clean
	@$(RM) -rf $(TARGETDIR)

# install to path
install: $(TARGET)
	@cp $(TARGETDIR)/$(TARGET) $(INSTALLBIN)
	@cp -R . $(INSTALLDIR)/$(TARGET)

uninstall:
	rm -f $(INSTALLBIN)/$(TARGET)
	rm -rf $(INSTALLDIR)/$(TARGET)

# pull dependencies
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^

# compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

# non-file targets
.PHONY: all remake clean cleaner
