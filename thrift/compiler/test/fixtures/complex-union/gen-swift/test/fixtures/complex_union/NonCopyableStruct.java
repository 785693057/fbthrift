/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.complex_union;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@ThriftStruct(value="NonCopyableStruct", builder=NonCopyableStruct.Builder.class)
public final class NonCopyableStruct {
    @ThriftConstructor
    public NonCopyableStruct(
        @ThriftField(value=1, name="num", requiredness=Requiredness.NONE) final long num
    ) {
        this.num = num;
    }
    
    @ThriftConstructor
    protected NonCopyableStruct() {
      this.num = 0L;
    }
    
    public static class Builder {
        private long num = 0L;
    
        @ThriftField(value=1, name="num", requiredness=Requiredness.NONE)
        public Builder setNum(long num) {
            this.num = num;
            return this;
        }
        
        public long getNum() { return num; }
    
        public Builder() { }
        public Builder(NonCopyableStruct other) {
            this.num = other.num;
        }
    
        @ThriftConstructor
        public NonCopyableStruct build() {
            return new NonCopyableStruct (
                this.num
            );
        }
    }
    
    private static final TStruct STRUCT_DESC = new TStruct("NonCopyableStruct");
    private final long num;
    public static final int _NUM = 1;
    private static final TField NUM_FIELD_DESC = new TField("num", TType.I64, (short)1);

    
    @ThriftField(value=1, name="num", requiredness=Requiredness.NONE)
    public long getNum() { return num; }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("num", num);
        return helper.toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        NonCopyableStruct other = (NonCopyableStruct)o;
    
        return
            Objects.equals(num, other.num) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            num
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static NonCopyableStruct read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      NonCopyableStruct.Builder builder = new NonCopyableStruct.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _NUM:
          if (__field.type == TType.I64) {
            long num = oprot.readI64();
            builder.setNum(num);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(NUM_FIELD_DESC);
      oprot.writeI64(this.num);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
