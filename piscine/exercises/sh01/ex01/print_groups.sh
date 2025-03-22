#!/bin/bash
id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'

#id command retrieves groups a user belongs to
#-G gives the group names, -n only shows names
# $FT_USER is the variable that id will look through
# tr is used for translating / replacing characters. In this case it replaces the space with a comma.
