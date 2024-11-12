# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcatete <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 17:11:34 by vcatete           #+#    #+#              #
#    Updated: 2024/11/11 17:11:37 by vcatete          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = megaphone

all: $(TARGET)

$(TARGET): megaphone.cpp
	$(CXX) $(CXXFLAGS) megaphone.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

