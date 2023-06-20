#include <cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include "../state/state.hpp"
#include "./submission.hpp"
using namespace std;

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move sub::get_move(State *state, int depth){
    Move action;
    int state_value=-1e9;
    if(!state->legal_actions.size())
      state->get_legal_actions();
    bool first;
    if(state->player==0) first=true;
    else first=false;
    for(auto &it: state->legal_actions){
        int value=Sub(state->next_state(it),depth-1,-1e9,1e9,true,first);
        if(value >= state_value){
            action=it;
            state_value=value;
        }
    }
    return action;
}

int sub::Sub(State *state,int depth,int a,int b,bool isopponent,bool first){
int value;
//state->get_legal_actions();
auto actions=state->legal_actions;
//state->game_state==WIN||state->game_state==DRAW||
  if(depth ==0||actions.empty()){
    return state->evaluate(first);
  }
  if(!isopponent){
    value=-1e9;
    for(auto &it: actions){
        value=max(value,Sub(state->next_state(it),depth-1,a,b,true,first));
        a=max(a,value);
        if(a>=b){
            break;
        }
    }
    return value;
  }
  if(isopponent){
    value=1e9;
    for(auto &it : actions){
        value=min(value,Sub(state->next_state(it),depth-1,a,b,false,first));
        b=min(b,value);
        if(b<=a){
            break;
        }
    }
    return value;
  }
}