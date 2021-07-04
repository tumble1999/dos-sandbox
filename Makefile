\=\\
CC=gcc

SOURCES=src
BUILD=build
OBJDIR=dos
OUTDIR=run
OUT=sandbox

OBJPATH=$(BUILD)$(\)$(OBJDIR)
OUTPATH=$(BUILD)$(\)$(OUTDIR)
TARGET=$(\)$(OUTPATH)$(\)$(OUT)

C_FILES=$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c )))
O_FILES=$(C_FILES:.c=.o)

$(TARGET).exe: $(O_FILES) $(OUTPATH)
	@cd $(OBJPATH);$(CC) -o $@ $(O_FILES)
	@echo $(OUT) has been linked from: $(O_FILES)

%.o: $(SOURCES)$(\)%.c $(OBJPATH)
	@$(CC) -c $< -o $(OBJPATH)$(\)$@
	@echo - $@

$(OBJPATH): $(BUILD)
	@mkdir $@
	@echo Created Object Directory

$(OUTPATH): $(BUILD)
	@mkdir $@
	@echo Created Output Directory

$(BUILD):
	@mkdir $@
	@echo Created Build Directory
