KERN=vector_dma_2x
TARGET=$(KERN).ll
%.o : %.c
	clang -emit-llvm -c -o $@ $<
%.bc : %.o
	opt -O1 -mem2reg -simplifycfg -loops -loop-unroll -o $@ $<
%.ll : %.bc
	llvm-dis -o $@ $<
build : $(TARGET)

clean:
	rm -f *.ll
