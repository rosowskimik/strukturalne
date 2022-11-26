TARGET := a.out
CODEDIRS := .
INCDIRS :=

BUILD_DIR := ./build

DIST_TARGET := rosowski_$(TARGET).zip

CC := gcc
OPT := -O0
STD := c99

DEPFLAGS := -MP -MD
INCFLAGS := $(addprefix -I,$(INCDIRS))
CFLAGS := -Wall -Wextra -g -std=$(STD) $(INCFLAGS) $(OPT) $(DEPFLAGS)

CFILES := $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS := $(CFILES:%=$(BUILD_DIR)/%.o)
DEPFILES := $(OBJECTS:.o=.d)

.PHONY: all
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(DIST_TARGET)

.PHONY: run
run: $(BUILD_DIR)/$(TARGET)
	$(info Running $(TARGET)...)
	$(info )
	@./$(BUILD_DIR)/$(TARGET)

dist: clean
	7z a -tzip $(DIST_TARGET) ./*

diff:
	@git status
	@git diff --stat

-include $(DEPFILES)
