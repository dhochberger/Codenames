EXT = cpp
CXX = g++ -std=c++11 
EXEC = CodeNames
 
CXXFLAGS =
LDFLAGS = 

BINDIR = bin
SRCDIR = src
OBJDIR = obj
SRC  = $(wildcard $(SRCDIR)/*.$(EXT))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
 
all: $(EXEC)
 
$(EXEC): $(OBJ)
	@[ -d $(BINDIR) ] || mkdir $(BINDIR)
	$(CXX) -o $(BINDIR)/$@ $^ $(LDFLAGS)
	@[ -h $@ ] || ln -s $(BINDIR)/$@ $@
 
$(OBJDIR)/%.o: %.$(EXT)
	$(CXX) -o $@ -c $< $(CXXFLAGS)
 
clean:
	rm -rf $(OBJDIR)/*.o
	rm -f $(EXEC)