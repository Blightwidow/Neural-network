EXECUTABLE = framework_poc

all: $(EXECUTABLE)

framework_poc: framework_poc.cc neuralNet.hcc neuralNeuron.hcc dataReader.hcc
	g++ -g -std=c++11 -Wall $< -o _$@

set: create-dataset.cc 
	g++ -g -std=c++11 -Wall $< -o $@
	@./$@ 
	@rm -f  $@
	@echo "Data sets created !"

clean:
	rm -f _hello_neural
	