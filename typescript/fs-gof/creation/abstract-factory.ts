type WindowProperties = {
  title: string;
};

type ScrollBarProperties = {
  orientation: "vertical" | "horizontal";
};

type WindowWidget = {
  render: () => void;
};

type ScrollBarWidget = {
  scrollTo: (position: number) => void;
};

type WidgetCreation = {
  createWindow: (properties: WindowProperties) => WindowWidget;
  createScrollBar: (properties: ScrollBarProperties) => ScrollBarWidget;
};

// We only define the factory object.
declare const widgetFactory: WidgetCreation;

widgetFactory.createScrollBar({
  orientation: "horizontal",
});
