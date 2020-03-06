CSRC    = $(SRC)
TARGET  = blackscholes
M4_BASE = .

M4_SRC    = blackscholes.cpp
CSRC      = $(M4_SRC)
MT        = -DENABLE_THREADS
CXXFLAGS += -pthread

INC += -I../../hooks
HOOKS += -DENABLE_ZSIM_HOOKS

# Default build single precision version
NCO     = -DNCO=4

ifdef chk_err
ERR     = -DERR_CHK
endif

ifdef single
NCO = -DNCO=4
endif

ifdef size
SZ = -DN=$(size)
else
SZ = -DN=960
endif

ifdef double
NCO = -DNCO=2
endif

CXXFLAGS += $(HOOKS) $(MT) $(NCO) $(FUNC) $(ERR) $(CSRC)

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INC) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)

install:
	mkdir -p ../bin
	cp -f $(TARGET) ../bin/$(TARGET)

