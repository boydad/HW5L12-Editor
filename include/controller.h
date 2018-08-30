#pragma once

#include <fstream>
#include "figures.h"
#include "model.h"
#include "IShower.h"


class Controller{
  Model& model;
  IShower* view;
    
public:
  
  Controller(Model& model): model(model) {};
  
  void subscribe(IShower* view){
    this->view = view;
  }
  
  void newDocument(const std::string& path){
    view->show(model.prepareBoard());
  }
  
  void importFrom(const std::string& path){
    std::ifstream file(path, std::ifstream::in);
    model.loadDataFrom(file);
    view->show(model.prepareBoard());
  }
    
  void exportAs(const std::string& path){
    std::ofstream file(path);
    model.saveDate(file);
    exit(0);
  }
  
  void add(std::unique_ptr<IFigure>&& fig){
    model.add(fig);
    view->show(model.prepareBoard());
  }
  
  void deleteFigure(const int id){
    model.remove(id);
    view->show(model.prepareBoard());
  }
  
  const decltype(auto) getPossibleFigures(){
    return (model.getFigureTypes());
  }
  
};