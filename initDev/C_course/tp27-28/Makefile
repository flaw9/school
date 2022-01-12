%.o: %.c %.h
	$(COMPILE.c) executables/$(OUTPUT_OPTION) $<

bst: identite.o abr.o bst.o
clean:
	$(RM) executables/*.o executables/bst