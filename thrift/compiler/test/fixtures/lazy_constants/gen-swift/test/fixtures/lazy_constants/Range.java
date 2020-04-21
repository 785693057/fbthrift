/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.lazy_constants;

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
@ThriftStruct(value="Range", builder=Range.Builder.class)
public final class Range {
    @ThriftConstructor
    public Range(
        @ThriftField(value=1, name="min", requiredness=Requiredness.REQUIRED) final int min,
        @ThriftField(value=2, name="max", requiredness=Requiredness.REQUIRED) final int max
    ) {
        this.min = min;
        this.max = max;
    }
    
    @ThriftConstructor
    protected Range() {
      this.min = 0;
      this.max = 0;
    }
    
    public static class Builder {
        private int min = 0;
        private int max = 0;
    
        @ThriftField(value=1, name="min", requiredness=Requiredness.REQUIRED)
        public Builder setMin(int min) {
            this.min = min;
            return this;
        }
        
        public int getMin() { return min; }
    
            @ThriftField(value=2, name="max", requiredness=Requiredness.REQUIRED)
        public Builder setMax(int max) {
            this.max = max;
            return this;
        }
        
        public int getMax() { return max; }
    
        public Builder() { }
        public Builder(Range other) {
            this.min = other.min;
            this.max = other.max;
        }
    
        @ThriftConstructor
        public Range build() {
            return new Range (
                this.min,
                this.max
            );
        }
    }
    
    private static final TStruct STRUCT_DESC = new TStruct("Range");
    private final int min;
    public static final int _MIN = 1;
    private static final TField MIN_FIELD_DESC = new TField("min", TType.I32, (short)1);
    private final int max;
    public static final int _MAX = 2;
    private static final TField MAX_FIELD_DESC = new TField("max", TType.I32, (short)2);

    
    @ThriftField(value=1, name="min", requiredness=Requiredness.REQUIRED)
    public int getMin() { return min; }
        
    @ThriftField(value=2, name="max", requiredness=Requiredness.REQUIRED)
    public int getMax() { return max; }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("min", min);
        helper.add("max", max);
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
    
        Range other = (Range)o;
    
        return
            Objects.equals(min, other.min) &&
            Objects.equals(max, other.max) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            min,
            max
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static Range read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      Range.Builder builder = new Range.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _MIN:
          if (__field.type == TType.I32) {
            int min = oprot.readI32();
            builder.setMin(min);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _MAX:
          if (__field.type == TType.I32) {
            int max = oprot.readI32();
            builder.setMax(max);
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
      oprot.writeFieldBegin(MIN_FIELD_DESC);
      oprot.writeI32(this.min);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(MAX_FIELD_DESC);
      oprot.writeI32(this.max);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
