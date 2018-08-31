#pragma once
#include <unordered_map>
#include <string>

#include "figures.h"
#include "controller.h"

//Simple graphic element
class Widget{  
  virtual void click() = 0;
protected:
  //key is label of text window
  //value is value os text window
  std::unordered_map<std::string, std::string> textFields;
  
  //The label of the Widget
  const char* label;
  
  Widget(const char* label): label(label) {};
  
  
public:
  
  virtual ~Widget() = default;
  
  const auto& getFields(){
    return textFields;
  }

  const auto& getLabel(){
    return label;
  }    
};


class FigureWidget: public Widget{
  IFigure& fig;
  Controller& handler;
  using Widget::textFields;
  using Widget::label;
  
public:
  FigureWidget(Controller& handler, IFigure& figure): Widget(figure.getName()),
        fig(figure), handler(handler){
    for(const auto& attrName: fig.showAttributeNames())
      textFields[attrName] = "";
  };  
  
  void click() override{
    for(const auto& attrName: fig.showAttributeNames())
      fig.set(attrName, textFields[attrName]);
    handler.add(fig.clone());    
  }  
};


class FigureDeleterWidget: public Widget{
  using Widget::textFields;
  Controller& handler;
  
public:
  
  FigureDeleterWidget(Controller& handler): Widget("Delete Figure"), 
        handler(handler){
    textFields["ID"] = "";
  }
  
  void click() override{
    const int id = stoi(textFields["ID"]);
    handler.deleteFigure(id);
  }  
};
  

class ExporterWidget: public Widget{
  using Widget::textFields;
  Controller& handler;
  
public:
  
  ExporterWidget(Controller& handler): Widget("Export As"),
        handler(handler){
    textFields["File name"] = "";
  }
  
  void click() override{
    handler.exportAs(textFields["File name"]);
  }
};


class ImporterWidger: public Widget{
  using Widget::textFields;
  Controller& handler;
  
public:
  
  ImporterWidger(Controller& handler): Widget("Import from"),
        handler(handler){
    textFields["File name"] = "";
  }
  
  void click() override{
    handler.importFrom(textFields["File name"]);
  }  
};


class NewDocumetWidger: public Widget{
  using Widget::textFields;
  Controller& handler;
  
public:
  
  NewDocumetWidger(Controller& handler): Widget("Create new document"),
        handler(handler){
    textFields["File name"] = "";
  }
  
  void click() override{
    handler.newDocument(textFields["File name"]);
  }  
};