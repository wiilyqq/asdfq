#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class alpha{
public:
  static Move get_move(State *state, int depth);
  static int Alpha(State *state,int depth,int a,int b,bool isoppnent,bool first);
};