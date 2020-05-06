<?hh // strict
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift enum:-
 * TestEnum
 */
enum TestEnum: int {
  UNKNOWN = 0;
  NEW_VALUE = 1;
}

enum TestUnionEnum: int {
  _EMPTY_ = 0;
  int_value = 1;
  str_value = 2;
  double_value = 3;
  list_of_strings = 4;
  map_of_string_to_ints = 5;
  struct_foo = 6;
}

/**
 * Original thrift struct:-
 * TestUnion
 */
class TestUnion implements \IThriftStruct, \IThriftUnion<TestUnionEnum>, \IThriftShapishStruct {
  use \ThriftUnionSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'int_value',
      'union' => true,
      'type' => \TType::I32,
    ),
    2 => shape(
      'var' => 'str_value',
      'union' => true,
      'type' => \TType::STRING,
    ),
    3 => shape(
      'var' => 'double_value',
      'union' => true,
      'type' => \TType::DOUBLE,
    ),
    4 => shape(
      'var' => 'list_of_strings',
      'union' => true,
      'type' => \TType::LST,
      'etype' => \TType::STRING,
      'elem' => shape(
        'type' => \TType::STRING,
      ),
      'format' => 'array',
    ),
    5 => shape(
      'var' => 'map_of_string_to_ints',
      'union' => true,
      'type' => \TType::MAP,
      'ktype' => \TType::STRING,
      'vtype' => \TType::I32,
      'key' => shape(
        'type' => \TType::STRING,
      ),
      'val' => shape(
        'type' => \TType::I32,
      ),
      'format' => 'array',
    ),
    6 => shape(
      'var' => 'struct_foo',
      'union' => true,
      'type' => \TType::STRUCT,
      'class' => Foo::class,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'int_value' => 1,
    'str_value' => 2,
    'double_value' => 3,
    'list_of_strings' => 4,
    'map_of_string_to_ints' => 5,
    'struct_foo' => 6,
  ];
  const type TConstructorShape = shape(
    ?'int_value' => ?int,
    ?'str_value' => ?string,
    ?'double_value' => ?float,
    ?'list_of_strings' => ?varray<string>,
    ?'map_of_string_to_ints' => ?darray<string, int>,
    ?'struct_foo' => ?Foo,
  );
  const type TShape = shape(
    ?'int_value' => ?int,
    ?'str_value' => ?string,
    ?'double_value' => ?float,
    ?'list_of_strings' => ?varray<string>,
    ?'map_of_string_to_ints' => ?darray<string, int>,
    ?'struct_foo' => ?Foo::TShape,
  );
  const int STRUCTURAL_ID = 872350750526219001;
  /**
   * Original thrift field:-
   * 1: i32 int_value
   */
  public ?int $int_value;
  /**
   * Original thrift field:-
   * 2: string str_value
   */
  public ?string $str_value;
  /**
   * Original thrift field:-
   * 3: double double_value
   */
  public ?float $double_value;
  /**
   * Original thrift field:-
   * 4: list<string> list_of_strings
   */
  public ?varray<string> $list_of_strings;
  /**
   * Original thrift field:-
   * 5: map<string, i32> map_of_string_to_ints
   */
  public ?darray<string, int> $map_of_string_to_ints;
  /**
   * Original thrift field:-
   * 6: struct module.Foo struct_foo
   */
  public ?Foo $struct_foo;
  protected TestUnionEnum $_type = TestUnionEnum::_EMPTY_;

  <<__Rx>>
  public function __construct(self::TConstructorShape $shape = shape()) {
    $this->_type = TestUnionEnum::_EMPTY_;
    $this->int_value = Shapes::idx($shape, 'int_value');
    if ($this->int_value !== null) {
        $this->_type = TestUnionEnum::int_value;
    }
    $this->str_value = Shapes::idx($shape, 'str_value');
    if ($this->str_value !== null) {
        $this->_type = TestUnionEnum::str_value;
    }
    $this->double_value = Shapes::idx($shape, 'double_value');
    if ($this->double_value !== null) {
        $this->_type = TestUnionEnum::double_value;
    }
    $this->list_of_strings = Shapes::idx($shape, 'list_of_strings');
    if ($this->list_of_strings !== null) {
        $this->_type = TestUnionEnum::list_of_strings;
    }
    $this->map_of_string_to_ints = Shapes::idx($shape, 'map_of_string_to_ints');
    if ($this->map_of_string_to_ints !== null) {
        $this->_type = TestUnionEnum::map_of_string_to_ints;
    }
    $this->struct_foo = Shapes::idx($shape, 'struct_foo');
    if ($this->struct_foo !== null) {
        $this->_type = TestUnionEnum::struct_foo;
    }
  }

  public function getName(): string {
    return 'TestUnion';
  }

  public function getType(): TestUnionEnum {
    return $this->_type;
  }

  public function set_int_value(int $int_value): this {
    $this->_type = TestUnionEnum::int_value;
    $this->int_value = $int_value;
    return $this;
  }

  public function get_int_value(): int {
    invariant(
      $this->_type === TestUnionEnum::int_value,
      'get_int_value called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return \nullthrows($this->int_value);
  }

  public function set_str_value(string $str_value): this {
    $this->_type = TestUnionEnum::str_value;
    $this->str_value = $str_value;
    return $this;
  }

  public function get_str_value(): string {
    invariant(
      $this->_type === TestUnionEnum::str_value,
      'get_str_value called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return \nullthrows($this->str_value);
  }

  public function set_double_value(float $double_value): this {
    $this->_type = TestUnionEnum::double_value;
    $this->double_value = $double_value;
    return $this;
  }

  public function get_double_value(): float {
    invariant(
      $this->_type === TestUnionEnum::double_value,
      'get_double_value called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return \nullthrows($this->double_value);
  }

  public function set_list_of_strings(varray<string> $list_of_strings): this {
    $this->_type = TestUnionEnum::list_of_strings;
    $this->list_of_strings = $list_of_strings;
    return $this;
  }

  public function get_list_of_strings(): varray<string> {
    invariant(
      $this->_type === TestUnionEnum::list_of_strings,
      'get_list_of_strings called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return \nullthrows($this->list_of_strings);
  }

  public function set_map_of_string_to_ints(darray<string, int> $map_of_string_to_ints): this {
    $this->_type = TestUnionEnum::map_of_string_to_ints;
    $this->map_of_string_to_ints = $map_of_string_to_ints;
    return $this;
  }

  public function get_map_of_string_to_ints(): darray<string, int> {
    invariant(
      $this->_type === TestUnionEnum::map_of_string_to_ints,
      'get_map_of_string_to_ints called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return \nullthrows($this->map_of_string_to_ints);
  }

  public function set_struct_foo(Foo $struct_foo): this {
    $this->_type = TestUnionEnum::struct_foo;
    $this->struct_foo = $struct_foo;
    return $this;
  }

  public function get_struct_foo(): Foo {
    invariant(
      $this->_type === TestUnionEnum::struct_foo,
      'get_struct_foo called on an instance of TestUnion whose current type is %s',
      (string)$this->_type,
    );
    return \nullthrows($this->struct_foo);
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }
  public static function __fromShape(self::TShape $shape): this {
    $me = new static();
    $me->_type = TestUnionEnum::_EMPTY_;
    if (Shapes::idx($shape, 'int_value') !== null) {
      $me->int_value = $shape['int_value'];
      $me->_type = TestUnionEnum::int_value;
    }
    if (Shapes::idx($shape, 'str_value') !== null) {
      $me->str_value = $shape['str_value'];
      $me->_type = TestUnionEnum::str_value;
    }
    if (Shapes::idx($shape, 'double_value') !== null) {
      $me->double_value = $shape['double_value'];
      $me->_type = TestUnionEnum::double_value;
    }
    if (Shapes::idx($shape, 'list_of_strings') !== null) {
      $me->list_of_strings = $shape['list_of_strings'];
      $me->_type = TestUnionEnum::list_of_strings;
    }
    if (Shapes::idx($shape, 'map_of_string_to_ints') !== null) {
      $me->map_of_string_to_ints = $shape['map_of_string_to_ints'];
      $me->_type = TestUnionEnum::map_of_string_to_ints;
    }
    if (Shapes::idx($shape, 'struct_foo') !== null) {
      $me->struct_foo = Foo::__fromShape($shape['struct_foo']);
      $me->_type = TestUnionEnum::struct_foo;
    }
    return $me;
  }

  <<__Rx>>
  public function __toShape(): self::TShape {
    return shape(
      'int_value' => $this->int_value,
      'str_value' => $this->str_value,
      'double_value' => $this->double_value,
      'list_of_strings' => $this->list_of_strings,
      'map_of_string_to_ints' => $this->map_of_string_to_ints,
      'struct_foo' => $this->struct_foo?->__toShape(),
    );
  }
}

/**
 * Original thrift struct:-
 * Foo
 */
class Foo implements \IThriftStruct, \IThriftShapishStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'a',
      'type' => \TType::LST,
      'etype' => \TType::STRING,
      'elem' => shape(
        'type' => \TType::STRING,
      ),
      'format' => 'array',
    ),
    2 => shape(
      'var' => 'b',
      'type' => \TType::MAP,
      'ktype' => \TType::STRING,
      'vtype' => \TType::LST,
      'key' => shape(
        'type' => \TType::STRING,
      ),
      'val' => shape(
        'type' => \TType::LST,
        'etype' => \TType::SET,
        'elem' => shape(
          'type' => \TType::SET,
          'etype' => \TType::I32,
          'elem' => shape(
            'type' => \TType::I32,
          ),
          'format' => 'array',
        ),
        'format' => 'array',
      ),
      'format' => 'array',
    ),
    3 => shape(
      'var' => 'c',
      'type' => \TType::I64,
    ),
    4 => shape(
      'var' => 'd',
      'type' => \TType::BOOL,
    ),
    5 => shape(
      'var' => 'str_value',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'a' => 1,
    'b' => 2,
    'c' => 3,
    'd' => 4,
    'str_value' => 5,
  ];
  const type TConstructorShape = shape(
    ?'a' => varray<string>,
    ?'b' => ?darray<string, varray<dict<int, bool>>>,
    ?'c' => int,
    ?'d' => bool,
    ?'str_value' => string,
  );
  const type TShape = shape(
    'a' => varray<string>,
    ?'b' => ?darray<string, varray<dict<int, bool>>>,
    'c' => int,
    'd' => bool,
    'str_value' => string,
  );
  const int STRUCTURAL_ID = 5952652426480946901;
  /**
   * Original thrift field:-
   * 1: list<string> a
   */
  public varray<string> $a;
  /**
   * Original thrift field:-
   * 2: map<string, list<set<i32>>> b
   */
  public ?darray<string, varray<dict<int, bool>>> $b;
  /**
   * Original thrift field:-
   * 3: i64 c
   */
  public int $c;
  /**
   * Original thrift field:-
   * 4: bool d
   */
  public bool $d;
  /**
   * Original thrift field:-
   * 5: string str_value
   */
  public string $str_value;

  <<__Rx>>
  public function __construct(self::TConstructorShape $shape = shape()) {
    $this->a = Shapes::idx($shape, 'a') ?? varray[];
    $this->b = Shapes::idx($shape, 'b');
    $this->c = Shapes::idx($shape, 'c') ?? 7;
    $this->d = Shapes::idx($shape, 'd') ?? false;
    $this->str_value = Shapes::idx($shape, 'str_value') ?? "hello";
  }

  public function getName(): string {
    return 'Foo';
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }
  public static function __fromShape(self::TShape $shape): this {
    $me = new static();
    $me->a = $shape['a'];
    if (Shapes::idx($shape, 'b') !== null) {
      $me->b = $shape['b'];
    }
    $me->c = $shape['c'];
    $me->d = $shape['d'];
    $me->str_value = $shape['str_value'];
    return $me;
  }

  <<__Rx>>
  public function __toShape(): self::TShape {
    return shape(
      'a' => $this->a,
      'b' => $this->b,
      'c' => $this->c,
      'd' => $this->d,
      'str_value' => $this->str_value,
    );
  }
}

/**
 * Original thrift struct:-
 * TestStruct
 */
class TestStruct implements \IThriftStruct, \IThriftShapishStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'foo_struct',
      'type' => \TType::STRUCT,
      'class' => Foo::class,
    ),
    2 => shape(
      'var' => 'union_value',
      'type' => \TType::STRUCT,
      'class' => TestUnion::class,
    ),
    3 => shape(
      'var' => 'struct_of_self',
      'type' => \TType::STRUCT,
      'class' => TestStruct::class,
    ),
    4 => shape(
      'var' => 'list_of_struct_foo',
      'type' => \TType::LST,
      'etype' => \TType::STRUCT,
      'elem' => shape(
        'type' => \TType::STRUCT,
        'class' => Foo::class,
      ),
      'format' => 'array',
    ),
    5 => shape(
      'var' => 'map_of_string_to_struct_foo',
      'type' => \TType::MAP,
      'ktype' => \TType::STRING,
      'vtype' => \TType::STRUCT,
      'key' => shape(
        'type' => \TType::STRING,
      ),
      'val' => shape(
        'type' => \TType::STRUCT,
        'class' => Foo::class,
      ),
      'format' => 'array',
    ),
    6 => shape(
      'var' => 'list_of_struct_self',
      'type' => \TType::LST,
      'etype' => \TType::STRUCT,
      'elem' => shape(
        'type' => \TType::STRUCT,
        'class' => TestStruct::class,
      ),
      'format' => 'array',
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'foo_struct' => 1,
    'union_value' => 2,
    'struct_of_self' => 3,
    'list_of_struct_foo' => 4,
    'map_of_string_to_struct_foo' => 5,
    'list_of_struct_self' => 6,
  ];
  const type TConstructorShape = shape(
    ?'foo_struct' => ?Foo,
    ?'union_value' => ?TestUnion,
    ?'struct_of_self' => ?TestStruct,
    ?'list_of_struct_foo' => varray<Foo>,
    ?'map_of_string_to_struct_foo' => darray<string, Foo>,
    ?'list_of_struct_self' => varray<TestStruct>,
  );
  const type TShape = shape(
    ?'foo_struct' => ?Foo::TShape,
    ?'union_value' => ?TestUnion::TShape,
    ?'struct_of_self' => ?TestStruct::TShape,
    'list_of_struct_foo' => varray<Foo::TShape>,
    'map_of_string_to_struct_foo' => darray<string, Foo::TShape>,
    'list_of_struct_self' => varray<TestStruct::TShape>,
  );
  const int STRUCTURAL_ID = 6681594433718475023;
  /**
   * Original thrift field:-
   * 1: struct module.Foo foo_struct
   */
  public ?Foo $foo_struct;
  /**
   * Original thrift field:-
   * 2: struct module.TestUnion union_value
   */
  public ?TestUnion $union_value;
  /**
   * Original thrift field:-
   * 3: struct module.TestStruct struct_of_self
   */
  public ?TestStruct $struct_of_self;
  /**
   * Original thrift field:-
   * 4: list<struct module.Foo> list_of_struct_foo
   */
  public varray<Foo> $list_of_struct_foo;
  /**
   * Original thrift field:-
   * 5: map<string, struct module.Foo> map_of_string_to_struct_foo
   */
  public darray<string, Foo> $map_of_string_to_struct_foo;
  /**
   * Original thrift field:-
   * 6: list<struct module.TestStruct> list_of_struct_self
   */
  public varray<TestStruct> $list_of_struct_self;

  <<__Rx>>
  public function __construct(self::TConstructorShape $shape = shape()) {
    $this->foo_struct = Shapes::idx($shape, 'foo_struct');
    $this->union_value = Shapes::idx($shape, 'union_value');
    $this->struct_of_self = Shapes::idx($shape, 'struct_of_self');
    $this->list_of_struct_foo = Shapes::idx($shape, 'list_of_struct_foo') ?? varray[];
    $this->map_of_string_to_struct_foo = Shapes::idx($shape, 'map_of_string_to_struct_foo') ?? darray[];
    $this->list_of_struct_self = Shapes::idx($shape, 'list_of_struct_self') ?? varray[];
  }

  public function getName(): string {
    return 'TestStruct';
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }
  public static function __fromShape(self::TShape $shape): this {
    $me = new static();
    if (Shapes::idx($shape, 'foo_struct') !== null) {
      $me->foo_struct = Foo::__fromShape($shape['foo_struct']);
    }
    if (Shapes::idx($shape, 'union_value') !== null) {
      $me->union_value = TestUnion::__fromShape($shape['union_value']);
    }
    if (Shapes::idx($shape, 'struct_of_self') !== null) {
      $me->struct_of_self = TestStruct::__fromShape($shape['struct_of_self']);
    }
    $me->list_of_struct_foo = $shape['list_of_struct_foo']
      |> Vec\map(
        $$,
        $_val0 ==> $_val0
          |> Foo::__fromShape($$),
      ) |> varray($$);
    $me->map_of_string_to_struct_foo = $shape['map_of_string_to_struct_foo']
      |> Dict\map(
        $$,
        $_val1 ==> $_val1
          |> Foo::__fromShape($$),
      ) |> darray($$);
    $me->list_of_struct_self = $shape['list_of_struct_self']
      |> Vec\map(
        $$,
        $_val2 ==> $_val2
          |> TestStruct::__fromShape($$),
      ) |> varray($$);
    return $me;
  }

  <<__Rx>>
  public function __toShape(): self::TShape {
    return shape(
      'foo_struct' => $this->foo_struct?->__toShape(),
      'union_value' => $this->union_value?->__toShape(),
      'struct_of_self' => $this->struct_of_self?->__toShape(),
      'list_of_struct_foo' => $this->list_of_struct_foo
        |> (
          Vec\map(
            $$,
            $_val0 ==> $_val0->__toShape(),
          ) |> varray($$)
        ),
      'map_of_string_to_struct_foo' => $this->map_of_string_to_struct_foo
        |> (
          Dict\map(
            $$,
            $_val0 ==> $_val0->__toShape(),
          ) |> darray($$)
        ),
      'list_of_struct_self' => $this->list_of_struct_self
        |> (
          Vec\map(
            $$,
            $_val0 ==> $_val0->__toShape(),
          ) |> varray($$)
        ),
    );
  }
}

/**
 * Original thrift exception:-
 * Baz
 */
class Baz extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'some_field',
      'type' => \TType::STRUCT,
      'class' => Foo::class,
    ),
    3 => shape(
      'var' => 'some_container',
      'type' => \TType::SET,
      'etype' => \TType::STRING,
      'elem' => shape(
        'type' => \TType::STRING,
      ),
      'format' => 'array',
    ),
    4 => shape(
      'var' => 'code',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
    'some_field' => 2,
    'some_container' => 3,
    'code' => 4,
  ];
  const type TConstructorShape = shape(
    ?'message' => string,
    ?'some_field' => ?Foo,
    ?'some_container' => dict<string, bool>,
    ?'code' => int,
  );
  const int STRUCTURAL_ID = 1663976252517274137;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;
  /**
   * Original thrift field:-
   * 2: struct module.Foo some_field
   */
  public ?Foo $some_field;
  /**
   * Original thrift field:-
   * 3: set<string> some_container
   */
  public dict<string, bool> $some_container;
  /**
   * Original thrift field:-
   * 4: i32 code
   */
  public int $code;

  <<__Rx>>
  public function __construct(self::TConstructorShape $shape = shape()) {
    parent::__construct();
    $this->message = Shapes::idx($shape, 'message') ?? '';
    $this->some_field = Shapes::idx($shape, 'some_field');
    $this->some_container = Shapes::idx($shape, 'some_container') ?? dict[];
    $this->code = Shapes::idx($shape, 'code') ?? 0;
  }

  public function getName(): string {
    return 'Baz';
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }
}

/**
 * Original thrift exception:-
 * OptBaz
 */
class OptBaz extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
  ];
  const type TConstructorShape = shape(
    ?'message' => ?string,
  );
  const int STRUCTURAL_ID = 546500496397478593;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;

  <<__Rx>>
  public function __construct(self::TConstructorShape $shape = shape()) {
    parent::__construct();
    $this->message = Shapes::idx($shape, 'message') ?? '';
  }

  public function getName(): string {
    return 'OptBaz';
  }

  public static function getAnnotations(): darray<string, mixed> {
    return darray[
    ];
  }
}

