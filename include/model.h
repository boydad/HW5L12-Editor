#pragma once

#include <unordered_map>
#include <memory>
#include <fstream>

#include "figures.h"
#include "board.h"
  
class Model{
  
private:  
  std::unordered_map<int, std::unique_ptr<IFigure> > figures;
  std::vector< std::unique_ptr<IFigure> > figureTypes; 
  
  Board board;
      
  void plotFiguresOnBoar() {};
  
public:
  Model() 
  {
    figureTypes.emplace_back(new Line);   
    figureTypes.emplace_back(new Box);    
    figureTypes.emplace_back(new Circle);
    figureTypes.emplace_back(new Point);
  }
  
  const std::vector< std::unique_ptr<IFigure> >& getFigureTypes(){
    return figureTypes;
  }
  
  void add(std::unique_ptr<IFigure>& fig){
    figures[fig->getId()] = std::move(fig);
  }
  
  void remove(const int id){
    figures.erase(id);
  }  
  
  const Board& prepareBoard(){
    this->plotFiguresOnBoar();
    return board;
  }
  
  void loadDataFrom(std::ifstream& file) {(void)(file);}
  
  void saveDate(std::ofstream& file) {(void)(file);};
  
  
};