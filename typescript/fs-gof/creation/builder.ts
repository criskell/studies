type BinOp = (lhs: number) => LackRhs;
type LackRhs = {
  (rhs: number): OpReady;
  lhs: (newLhs: number) => LackRhs;
};
type BinOp_OpReady = (lhs: number) => (rhs: number) => OpReady;
type OpReady = {
  (): number;
  lhs: (newLhs: number) => OpReady;
  rhs: (newRhs: number) => OpReady;
};

const sum: BinOp = (lhs) => {
  const baseLackRhs: LackRhs = (rhs) => {
    const baseOp: OpReady = () => lhs + rhs;
    baseOp.lhs = (newLhs) => sum(newLhs)(rhs);
    const rhsOverride = (newRhs: number) => {
      const baseOp2: OpReady = () => lhs + newRhs;
      baseOp2.lhs = (newLhs) => sum(newLhs)(newRhs);
      baseOp2.rhs = rhsOverride;
      return baseOp2;
    };
    baseOp.rhs = rhsOverride;
    return baseOp;
  };
  baseLackRhs.lhs = (newLhs) => sum(newLhs);
  return baseLackRhs;
};

const sub: BinOp = (lhs) => {
  const baseLackRhs: LackRhs = (rhs) => {
    const baseOp: OpReady = () => lhs - rhs;
    baseOp.lhs = (newLhs) => sub(newLhs)(rhs);
    const rhsOverride = (newRhs: number) => {
      const baseOp2: OpReady = () => lhs - newRhs;
      baseOp2.lhs = (newLhs) => sub(newLhs)(newRhs);
      baseOp2.rhs = rhsOverride;
      return baseOp2;
    };
    baseOp.rhs = rhsOverride;
    return baseOp;
  };
  baseLackRhs.lhs = (newLhs) => sub(newLhs);
  return baseLackRhs;
};

const mul: BinOp = (lhs) => {
  const baseLackRhs: LackRhs = (rhs) => {
    const baseOp: OpReady = () => lhs * rhs;
    baseOp.lhs = (newLhs) => mul(newLhs)(rhs);
    const rhsOverride = (newRhs: number) => {
      const baseOp2: OpReady = () => lhs * newRhs;
      baseOp2.lhs = (newLhs) => mul(newLhs)(newRhs);
      baseOp2.rhs = rhsOverride;
      return baseOp2;
    };
    baseOp.rhs = rhsOverride;
    return baseOp;
  };
  baseLackRhs.lhs = (newLhs) => mul(newLhs);
  return baseLackRhs;
};

const div: BinOp = (lhs) => {
  const baseLackRhs: LackRhs = (rhs) => {
    const baseOp: OpReady = () => (rhs === 0 ? 0 : lhs / rhs);
    baseOp.lhs = (newLhs) => div(newLhs)(rhs);
    const rhsOverride = (newRhs: number) => {
      const baseOp2: OpReady = () => (newRhs === 0 ? 0 : lhs / newRhs);
      baseOp2.lhs = (newLhs) => div(newLhs)(newRhs);
      baseOp2.rhs = rhsOverride;
      return baseOp2;
    };
    baseOp.rhs = rhsOverride;
    return baseOp;
  };
  baseLackRhs.lhs = (newLhs) => div(newLhs);
  return baseLackRhs;
};

console.log(sum(2)(2).rhs(3)());
console.log(sum(2)(2).lhs(3).rhs(3).lhs(2)());

console.log(div(mul(sub(6)(1)())(2)())(sum(1)(1)())());

console.log(sum(5).lhs(2)(2).rhs(3)());
console.log(sub(15).lhs(5)(3).rhs(2)());
