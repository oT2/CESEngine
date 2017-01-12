##
## Makefile for Makefile in /home/salabe_f/rendu/IA/Gomoku
##
## Made by francois salabelle
## Login   <salabe_f@epitech.net>
##
## Started on  Thu Nov  3 15:15:19 2016 francois salabelle
## Last update Fri Jan  6 02:10:43 2017 Clément Arnoux
##

NAME	= Engine

SRCS	= main.cpp \
	  CComponent.cpp \
	  Engine.cpp \
	  IFactory.cpp \
	  Msg.cpp \
	  MsgBox.cpp \
	  Client.cpp \
	  World.cpp \
	  Lobby.cpp \
	  Room.cpp \
	  ISocket.cpp \
	  LinuxSocket.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS += -std=c++11 -ldl -g -pthread

all: $(NAME) $(LIB) 
	$(COMP) 
	$(SYS)

$(NAME): $(OBJS)
	  g++ -o $(NAME) $(OBJS) $(CPPFLAGS)
	  g++ -fPIC -shared HandleBehaviour.cpp Engine.cpp CComponent.cpp -o libHandleBehaviourSystem.so $(CPPFLAGS)
	  g++ -fPIC -shared FactoryShip.cpp IFactory.cpp Engine.cpp CComponent.cpp -o libShip.so $(CPPFLAGS)
	  g++ -fPIC -shared FactoryMonster.cpp IFactory.cpp Engine.cpp CComponent.cpp -o libMonster.so $(CPPFLAGS)
	  g++ -fPIC -shared FactoryMissile.cpp IFactory.cpp Engine.cpp CComponent.cpp -o libMissile.so $(CPPFLAGS)
	  g++ -fPIC -shared Position.cpp -o libPositionComponent.so $(CPPFLAGS)
	  g++ -fPIC -shared Vector.cpp -o libVectorComponent.so $(CPPFLAGS)
	  g++ -fPIC -shared Speed.cpp -o libSpeedComponent.so $(CPPFLAGS)
	  g++ -fPIC -shared HitboxParam.cpp -o libHitboxParamComponent.so $(CPPFLAGS)
	  g++ -fPIC -shared Weapon.cpp -o libWeaponComponent.so	$(CPPFLAGS)
	  g++ -fPIC -shared Player.cpp -o libPlayerComponent.so	$(CPPFLAGS)
	  g++ -fPIC -shared Behaviour.cpp -o libBehaviourComponent.so $(CPPFLAGS)
	  g++ -fPIC -shared Type.cpp -o libTypeComponent.so $(CPPFLAGS)		
	  g++ -fPIC -shared Hitbox.cpp Msg.cpp Engine.cpp CComponent.cpp -o libHitboxSystem.so $(CPPFLAGS)
	  g++ -fPIC -shared Move.cpp Engine.cpp CComponent.cpp -o libMoveSystem.so $(CPPFLAGS)
	  g++ -fPIC -shared Shoot.cpp Engine.cpp CComponent.cpp IFactory.cpp -o libShootSystem.so $(CPPFLAGS)
	  g++ -fPIC -shared HandlePlayer.cpp Engine.cpp CComponent.cpp MsgBox.cpp Msg.cpp -o libHandlePlayerSystem.so $(CPPFLAGS)
	  g++ -fPIC -shared Display.cpp Engine.cpp CComponent.cpp -o libDisplaySystem.so $(CPPFLAGS)

clean:
	  rm -rf $(OBJS)

fclean: clean
	  rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
