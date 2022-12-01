TARGET := poker

BINARY := $(TARGET)
LIBRARY := lib$(TARGET).a

LIBDIRS := ./lib
CODEDIRS := $(LIBDIRS) .

LIBINC := ./lib
INC := $(LIBINC)

BUILD_DIR := ./build

SRC_TARGET := rosowski_$(TARGET).zip
LIB_TARGET := $(TARGET).tar.gz

CC := gcc
OPT := -O0
STD := c99

DEPFLAGS := -MP -MMD
INCFLAGS := $(addprefix -I,$(INC))
CFLAGS := -Wall -Wextra -g -std=$(STD) $(INCFLAGS) $(OPT) $(DEPFLAGS)

LIBCFILES := $(foreach D,$(LIBDIRS),$(wildcard $(D)/*.c))
LIBOBJECTS := $(LIBCFILES:%=$(BUILD_DIR)/%.o)
HFILES := $(foreach D,$(LIBINC),$(wildcard $(D)/*.h))

CFILES := $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS := $(CFILES:%=$(BUILD_DIR)/%.o)
DEPFILES := $(OBJECTS:.o=.d)

.PHONY: all
all: $(BUILD_DIR)/$(BINARY)

$(BUILD_DIR)/$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(DIST_TARGET)

.PHONY: lib
lib: $(LIBOBJECTS)
	mkdir -p $(BUILD_DIR)/include
	ar -rs $(BUILD_DIR)/$(LIBRARY) $(LIBOBJECTS)
	cp $(HFILES) $(BUILD_DIR)/include

.PHONY: run
run: $(BUILD_DIR)/$(TARGET)
	$(info Running $(TARGET)...)
	$(info )
	@./$(BUILD_DIR)/$(TARGET)

.PHONY: src
src: clean
	7z a -tzip $(SRC_TARGET) ./*

.PHONY: pack
pack: lib
	tar czf $(BUILD_DIR)/$(LIB_TARGET) $(BUILD_DIR)/$(LIBRARY) $(BUILD_DIR)/include

diff:
	@git status
	@git diff --stat

-include $(DEPFILES)
