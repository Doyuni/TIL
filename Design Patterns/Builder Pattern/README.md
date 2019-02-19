# Builder Pattern
* 하나의 객체를 생성할 때 객체를 이루는 구성요소들을 분리하여 각각 별도의 클래스들을 만들고 이 클래스들을 조합하여 하나의 객체를 만드는 패턴이다. 

## Why use this ?
* java를 예로 들면, 객체를 생성할 때 생성자의 인자가 객체마다 필요한 인자가 각각 다르고 혹은 필요한 인자가 많을 수도 있다.  
이럴 경우 Builder pattern을 적용하여 객체 생성을 깔끔하고 유연하게 할 수 있다.

### Telescoping Constructor Pattern ( 점층적 생성자 패턴 )
* 생성자의 인자를 하나씩 추가해가면서 정의하기에 점층적 생성자 패턴이라고 한다.
```java
public class FruitMenu {
    private final int grape;
    private final int orange;
    private final int strawberry;
    private final int banana;
    private final int apple;

    //필수 생성자
    public FruitMenu(int grape, int orange) {
        this(grape, orange);
    }
    // 1개의 선택적 인자를 받는 생성자
    public FruitMenu(int grape, int orange, int strawberry) {
        this(grape, orange, strawberry);
    }
    // 2개의 선택적 인자를 받는 생성자
    public FruitMenu(int grape, int orange, int strawberry, int banana) {
        this(grape, orange, strawberry, banana);
    }
    // 모든 선택적 인자를 받는 생성자
    public FruitMenu(int grape, int orange, int strawberry, int banana, int apple) {
        this.grape = grape;
        this.orange = orange;
        this.strawberry = strawberry;
        this.banana = banana;
        this.apple = apple;
    }
    
    public static void main(String[] args) {
        // 어떤 인자의 값인지 알기 어렵다.
        FruitMenu FruitOfKim = new FruitMenu(30, 21); 
        FruitMenu FruitOfLee = new FruitMenu(10, 20, 30, 10);
        FruitMenu FruitOfHong = new FruitMenu(10, 0, 0, 10);
    }
}
```
* 단점
  * 인자 수가 많을 때 객체를 생성하는 부분에서 어떤 인자의 값인지 알기 어렵다.
  * 인자가 많은 상황에서 인자가 추가되는 일이 발생할 때 코드 수정이 어렵다.
  * 필요 없는 인자를 전달해야 하는 경우가 생긴다. (ex. FruitOfHong 객체를 생성)
### JavaBeans Pattern
* 점층적 생성자 패턴에서 생성자의 인자 수가 많을 때 코드 작성이 어렵고 읽기 어려운 문제점을 해결하고자 사용하는 패턴이다.
* setter method를 사용해 객체 생성 코드의 가독성을 높여준다.
```java
public class FruitMenu {
    // 필수는 1, 옵션은 0
    private final int grape = 1;  
    private final int orange = 1;
    private final int strawberry = 0;
    private final int banana = 0;
    private final int apple = 0;

    public FruitMenu() {}

    public void setGrape(int grape) {
        this.grape = grape;
    }
    
    public void setOrange(int orange) {
        this.orange = orange;
    }

    public void setStrawberry(int strawberry) {
        this.strawberry = strawberry;
    }

    public void setBanana(int banana) {
        this.banana = banana;
    }

    public void setApple(int apple) {
        this.apple = apple;
    }
}

public class GetFruitMenu {
    public static void main(String[] args) {
        FruitMenu FruitOfHong = new FruitMenu();
        FruitOfHong.setGrape(10);
        FruitOfHong.setOrange(20);
        FruitOfHong.setStrawberry(7);
        FruitOfHong.setBanana(5);
    }
}
```
* 장점  
  * 객체 생성 시 어떤 인자의 값인지 알 수 있다.  
  * 필요 없는 인자는 신경쓰지 않아도 된다.

* 단점  
  * 객체의 일관성(consistency)이 깨진다.
   -> 한 번의 호출로 객체 생성이 끝나지 않고 여러 setter method를 호출해야 한다.  
  * 안정성을 확보할 수 없다.  
   -> setter method를 사용하기에 변경 불가능(immutable) 클래스를 만들 수 없다.  
### Builder Pattern
* 점층적 생성자 패턴의 안정성 + 자바빈 패턴의 가독성
```java
public class FruitMenu {
    // 각 인자가 final로 선언되어 변경 불가능하다.
    private final int grape;
    private final int orange;
    private final int strawberry;
    private final int banana;
    private final int apple;

    public static class Builder {
        // Required parameters (final로 선언되어 생성자를 통해 생성)
        private final int grape;
        private final int orange;
        // Optional parameters (Initialize default values)
        private int strawberry = 0;
        private int banana = 0;
        private int apple = 0;

        // Required constructor
        public Builder(int grape, int orange) {
            this.grape = grape;
            this.orange = orange;
        }

        // Method of Builder type
        public Builder strawberry(int num) {
            strawberry = num;
            return this;
        }

        public Builder banana(int num) {
            banana = num;
            return this;
        }

        public Builder apple(int num) {
            apple = num;
            return this;
        }
        // Builder 객체 자신을 FruitMenu type으로 반환한다.
        public FruitMenu build() {
            return new FruitMenu(this);
        }
    }
  
    private FruitMenu(Builder builder) {
        grape = builder.grape;
        orange = builder.orange;
        strawberry = builder.strawberry;
        banana = builder.banana;
        apple = builder.apple;
    }
}

public class GetFruitMenu {
    public static void main(String[] args) {
        // 방법 1
        FruitMenu.Builder builder = new FruitMenu.Builder(5, 7);
        builder.strawberry(2);
        builder.banana(10);
        builder.apple(9);
        FruitMenu FruitOfKim = builder.build();
        // 방법 2
        FruitMenu FruitOfHong = new FruitMenu.Builder(10, 20)
            .strawberry(7)
            .banana(10)
            .apple(3)
            .build();
    }
}
```
* 장점  
  * 어떤 인자의 값인지 알기 쉽다.
  * 변경 불가능(immutable) 객체를 만들 수 있다.
  * 객체의 일관성을 유지할 수 있다.
  * 인자가 많거나 선택적 인자가 많을 때 유용하다.  
 
 * 단점  
   * 코드가 길어질 수 있다.

