cc=gcc
test=fileserver fileclient

all:
	${cc} fileserver.c -o fileserver -lpthread
	${cc} 9361client.c -o fileclient -lpthread

clean:
	rm ${test}
