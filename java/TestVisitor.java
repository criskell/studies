import java.util.List;
import java.util.stream.Collectors;

public class TestVisitor {
    public static void main(String[] args) {
        Expr expr = new BinaryOp(
            BinaryOp.Op.MUL,
            new BinaryOp(BinaryOp.Op.ADD, new NumberLiteral(1), new NumberLiteral(2)),
            new Identifier("x")
        );

        RpnVisitor visitor = new RpnVisitor();
        String result = expr.accept(visitor);

        System.out.println("Output: " + result);
    }
}

// AST
interface Expr {
    <R> R accept(Visitor<R> v);
}

class NumberLiteral implements Expr {
    final int value;

    NumberLiteral(int value) {
        this.value = value;
    }

    public <R> R accept(Visitor<R> visitor) {
        return visitor.visitNumber(this);
    }
}

class Identifier implements Expr {
    final String name;

    Identifier(String name) {
        this.name = name;
    }

    public <R> R accept(Visitor<R> visitor) {
        return visitor.visitIdentifier(this);
    }
}

class BinaryOp implements Expr {
    enum Op { ADD, SUB, MUL, DIV }

    final Op op;
    final Expr left, right;

    BinaryOp(Op op, Expr left, Expr right) {
        this.op = op;
        this.left = left;
        this.right = right;
    }

    public <R> R accept(Visitor<R> visitor) {
        return visitor.visitBinary(this);
    }
}

class Call implements Expr {
    final Expr fun;
    final List<Expr> args;

    Call(Expr fun, List<Expr> args) {
        this.fun = fun;
        this.args = args;
    }

    public <R> R accept(Visitor<R> visitor) {
        return visitor.visitCall(this);
    }
}

class FieldAccess implements Expr {
    final Expr target;
    final String field;

    FieldAccess(Expr target, String field) {
        this.target = target;
        this.field = field;
    }

    public <R> R accept(Visitor<R> visitor) {
        return visitor.visitFieldAccess(this);
    }
}

interface Visitor<R> {
    R visitNumber(NumberLiteral number);
    R visitIdentifier(Identifier identifier);
    R visitBinary(BinaryOp binaryOp);
    R visitCall(Call call);
    R visitFieldAccess(FieldAccess fieldAccess);
}

class RpnVisitor implements Visitor<String> {
    public String visitNumber(NumberLiteral number) {
        return Integer.toString(number.value);
    }

    public String visitIdentifier(Identifier identifier) {
        return identifier.name;
    }

    public String visitBinary(BinaryOp binaryOp) {
        String left = binaryOp.left.accept(this);
        String right = binaryOp.right.accept(this);

        String op;

        switch (binaryOp.op) {
            case ADD: op = "+"; break;
            case SUB: op = "-"; break;
            case MUL: op = "*"; break;
            case DIV: op = "/"; break;
            default: op = "?";
        }

        return left + " " + right + " " + op;
    }

    public String visitCall(Call call) {
        String argsRpn = call.args.stream()
                         .map(argument -> argument.accept(this))
                         .collect(Collectors.joining(" "));

        String rpnFun = call.fun.accept(this);

        if (argsRpn.isEmpty()) return rpnFun + " call";

        return argsRpn + " " + rpnFun + " call";
    }

    public String visitFieldAccess(FieldAccess fieldAccess) {
        String target = fieldAccess.target.accept(this);

        return target + " ." + fieldAccess.field;
    }
}