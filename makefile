all:
	g++ -I/home/ubuntu/google-test/googletest/googletest/include -I/home/ubuntu/google-test/googletest/googlemock/include -pthread WordTreeInputTests.cpp WordTreeInput.cpp WordTree.cpp  WordTreeNode.cpp ~/google-test/googletest/googlemock/libgmock.a -o WordTreeInputTests -std=c++11
