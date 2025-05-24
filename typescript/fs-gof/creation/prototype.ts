type Car = {
  color: string;
  engine: ("eletric" | "gasoline" | "diesel" | "alcohol")[];
};

const factoryFromCarPrototype = (prototype: Car) => (custom: Partial<Car>) => ({
  ...prototype,
  ...custom,
});

const redCar: Car = {
  color: "red",
  engine: ["eletric", "gasoline"],
};

const factory = factoryFromCarPrototype(redCar);

const car1 = factory({ color: "green" });

console.log(car1);

const genericFactoryFromPrototype =
  <T>(prototype: T) =>
  (custom: Partial<T>) => ({
    ...prototype,
    ...custom,
  });

const factory2 = genericFactoryFromPrototype(car1);

const car2 = factory2({
  engine: ["alcohol"],
});

console.log(car2);

const car3 = factory2({
  color: "purple",
});

console.log(car3);
