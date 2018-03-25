
#declare variable
CC = g++
INCLUDE_FILES = ../Max_Heap/include ../Linked_List/include
INCLUDE_FLAGS = $(foreach d, $(INCLUDE_FILES), -I $d)
CTAGS_UTIL = /usr/local/bin/
CTAGS_FILES = ../Max_Heap ../Max_Heap/include ../Linked_List ../Linked_List/include
CTAGS_FLAGS = $(foreach d, $(CTAGS_FILES),-a $d/*)
CFLAGS = -g -Wall -O3 
COMPILE_FLAGS = -c
MAIN_OBJECT_NAME = merge_sort
#MAIN_OBJECT_NAME = merge_sort2
#MAIN_OBJECT_NAME = quick_sort
#MAIN_OBJECT_NAME = insertion_sort
#MAIN_OBJECT_NAME = selection_sort
MAIN_OBJECT_NAME_HEAP = heap_sort_main
MAIN_OBJECT_NAME_COUNTING_SORT = counting_sort
MAIN_OBJECT_NAME_RADIX_SORT = radix_sort
MAIN_OBJECT_SOURCE = $(MAIN_OBJECT_NAME).cpp
LINKED_LIST_MAIN = ../Linked_List/
MAIN_OBJECT_EXEC = $(MAIN_OBJECT_NAME).o
MAIN_OBJECT_EXEC_OUTPUT = ../exec_output/

all : clean
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(MAIN_OBJECT_SOURCE) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_EXEC)

heap_sort : clean_heap_sort heap all_file_tags
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(MAIN_OBJECT_NAME_HEAP).cpp $(MAIN_OBJECT_EXEC_OUTPUT)heap_sort.o -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_NAME_HEAP).o
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_NAME_HEAP).o

heap : heap_sort.cpp
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) heap_sort.cpp $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)heap_sort.o

counting_sort : clean_counting_sort linked_list all_file_tags
	$(CC) $(CFLAGS) $(MAIN_OBJECT_NAME_COUNTING_SORT).cpp $(MAIN_OBJECT_EXEC_OUTPUT)linked_list.o $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_NAME_COUNTING_SORT).o
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_NAME_COUNTING_SORT).o

radix_sort : clean_radix_sort linked_list all_file_tags
	$(CC) $(CFLAGS) $(MAIN_OBJECT_NAME_RADIX_SORT).cpp $(MAIN_OBJECT_EXEC_OUTPUT)linked_list.o $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_NAME_RADIX_SORT).o
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_NAME_RADIX_SORT).o

linked_list : clean_linked_list $(LINKED_LIST_MAIN)linked_list.cpp 
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) $(LINKED_LIST_MAIN)linked_list.cpp $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)linked_list.o

all_file_tags : 
	$(CTAGS_UTIL)ctags -R ./*
	$(CTAGS_UTIL)ctags $(CTAGS_FLAGS)

clean_counting_sort : clean_linked_list
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_NAME_COUNTING_SORT).o
	
clean_radix_sort : clean_linked_list
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_NAME_RADIX_SORT).o

clean_linked_list : 
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)linked_list.o

clean_heap_sort : 
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_NAME_HEAP).o

clean :
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)
