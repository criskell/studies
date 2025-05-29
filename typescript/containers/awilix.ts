// $ node --experimental-strip-types containers/awilix.ts

import {
  asClass,
  asFunction,
  asValue,
  createContainer,
  InjectionMode,
} from "awilix";

type Services = {
  userController: UserController;
  connectionString: string;
  timeout: number;
  db: InstanceType<typeof Database>;
  userService: ReturnType<typeof makeUserService>;
};

const container = createContainer<Services>({
  injectionMode: InjectionMode.PROXY,
  strict: true,
});

class UserController {
  #userService: Services["userService"];

  constructor(opts: Services) {
    this.#userService = opts.userService;
  }

  getUser(ctx: { params: { id: number } }) {
    return this.#userService.getUser(ctx.params.id);
  }
}

container.register({
  // Ensina como resolver "userController": instanciando a classe UserController.
  userController: asClass(UserController),
});

const makeUserService = ({ db }: { db: Database }) => {
  return {
    getUser: (id) => {
      return db.query("SELECT * FROM users WHERE id = ?", [id]);
    },
  };
};

container.register({
  userService: asFunction(makeUserService),
});

interface Database {
  connectionString: string;
  timeout: number;
  query(sql: string, params: string[]): void;
}

const Database = (() => {
  interface DatabaseConstructor {
    new (connectionString: string, timeout: number): Database;
  }

  function Database(this: Database, connectionString: string, timeout: number) {
    this.connectionString = connectionString;
    this.timeout = timeout;
  }

  const proto = Database.prototype;
  proto.query = function (this: Database, sql: string, params: string[]) {
    console.log(`Executing query: ${sql}`);
    console.log(`With params: ${params}`);
  };

  return Database as unknown as DatabaseConstructor;
})();

container.register({
  db: asClass(Database).classic(),
});

container.register({
  connectionString: asValue("mysql://localhost:3306/mydb"),
  timeout: asValue(5000),
});

container.cradle.userController.getUser({
  params: {
    id: 1,
  },
});

container.resolve("userController").getUser({
  params: {
    id: 2,
  },
});
