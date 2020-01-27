CXX=g++
GLADEOUT=gladeFile

all: build/kcorock

clean:
	rm -rf gui/$(GLADEOUT).{cpp,h,h.gch} $(GLADEOUT) *.o build

## Generate any required C++ source and headers:

gui/$(GLADEOUT).cpp gui/$(GLADEOUT).h: gui/kcorock.wxg
	wxglade -g C++ -o gui/$(GLADEOUT).cpp $<

## Compile and link

#$(GLADEOUT): $(GLADEOUT).o
#	$(CXX) `wx-config --libs` -o $@ $<

build:
	mkdir build

build/assets: gui/assets build
	cp -r gui/assets build/assets

build/kcorock: main/main.cpp gui/$(GLADEOUT).cpp build/assets
	$(CXX) -g -I. `wx-config --cxxflags --libs` $< gui/$(GLADEOUT).cpp -o $@
	