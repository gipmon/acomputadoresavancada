
TARGETS = arradd2 #arradd2 arradd3 arradd4 


all: $(TARGETS)


arradd1: arradd1.cu
	nvcc -arch=sm_13 -O arradd1.cu -o arradd1

arradd2: arradd2.cu
	nvcc -arch=sm_13 -O arradd2.cu -o arradd2

arradd3: arradd3.cu
	nvcc -arch=sm_13 -O arradd3.cu -o arradd3

arradd4: arradd4.cu
	nvcc -arch=sm_13 -O arradd4.cu -o arradd4

clean:
	rm $(TARGETS)
