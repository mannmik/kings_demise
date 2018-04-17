target:
	g++ Space.hpp Character.hpp Village.hpp Village.cpp Kitchen.hpp Kitchen.cpp Hallway.hpp Hallway.cpp BlackSmith.hpp BlackSmith.cpp GeneralHut.hpp GeneralHut.cpp KingsRoom.hpp KingsRoom.cpp Main_Final.cpp  -o game
clean:
	rm -f *o game
