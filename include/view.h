#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "controller.h"
#include "widgets.h"
#include "IShower.h"


class View: public IShowing{
  Controller& controller;
  std::vector< std::unique_ptr<Widget> > widgets;
  
  void showWidgets() {
    for(auto& wid: widgets){
      std::cout << "Widget: " << wid->getLabel() << '\n';
      for(auto& tf: wid->getFields())
        std::cout << "  " << tf.first << ": " << tf.second << '\n';
    }
  };
  
public:
  View(Controller& controller): controller(controller) {
    controller.subscribe(this);
    
    for(const auto& figure: controller.getPossibleFigures())
      widgets.emplace_back(new FigureWidget(controller, *figure));
    
    widgets.emplace_back(new FigureDeleterWidget(controller));    
    widgets.emplace_back(new ExporterWidget(controller));
    widgets.emplace_back(new ImporterWidger(controller));
    widgets.emplace_back(new NewDocumetWidger(controller));        
  };
  
  virtual void show(const Board& board) override { (void)(board);};  
  
  void start(){
    this->showWidgets();    
  }
  
};