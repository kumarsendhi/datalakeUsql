#pragma warning( disable : 4100 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4355 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4512 )
#pragma warning( disable:  4651 )
#pragma warning( disable : 4691 )
#pragma warning( disable : 4723 )
#pragma warning( disable : 4702 )
#define SCOPE_NO_UDT
#if defined(COMPILE_NATIVE)
#include "ScopeCommonError.h"
#include "ScopeError.h"
#include "ScopeOperators.h"
#endif
#if defined(COMPILE_MANAGED)
#using <mscorlib.dll>
[assembly: System::Runtime::Versioning::TargetFrameworkAttribute(".NETFramework,Version=v4.5", FrameworkDisplayName = ".NET Framework, Version 4.5")];
#include "ScopeCommonError.h"
#include "SqlManaged.h"
#endif
#if defined(COMPILE_NATIVE)
#endif
using namespace ScopeEngine;
static ScopeEngine::CompilerSettings GetCompilerSettings()
{
    static ScopeEngine::CompilerSettings settings;
    settings.m_restrictOperatorMemorySpilling = false;
    settings.m_verboseRuntimeStatistic = false;
    settings.m_vertexClassifyStoreError = true;
    return settings;
};

enum OperatorUID
{
UID_GetSStream_0 = 1,
UID_GetSStream_0_Data0 = 2,
UID_Process_1 = 3,
UID_SV1_Extract_out0 = 4,
UID_GetSStream_2 = 5,
UID_GetSStream_2_Data0 = 6,
UID_Process_3 = 7,
UID_Process_3_Data0 = 8,
UID_Process_4 = 9,
UID_SV2_Extract_out0 = 10,
UID_Join_5 = 11,
UID_Join_5_Data0 = 12,
UID_SV3_Combine_out0 = 13,
UID_Join_5_0,
UID_Join_5_1,
UID_Process_1_Prefix,
UID_Process_4_Prefix
};

#include <vector>
#include <unordered_map>

// Hasher
template<>
struct hash<GUID> : public _Bitwise_hash<GUID>
{
};

// Equals operator
template<>
struct equal_to<GUID>
{
    constexpr bool operator()(const GUID& _Left, const GUID& _Right) const
    {
        return static_cast<bool>(InlineIsEqualGUID(_Left, _Right));
    }
};

namespace
{
    typedef GUID StreamId;
    typedef int DistributionId;
    typedef int64_t VertexId;
    typedef int64_t RowId;

    typedef std::vector<RowId> RowIds;
    typedef std::unordered_map<StreamId, RowIds> StreamsToLastRowIdsMap;

#pragma warning( push )
#pragma warning( disable : 4592 )

    static StreamsToLastRowIdsMap s_streamsToLastRowIds({
    });

#pragma warning( pop )

    RowId GetNextRowId(StreamId streamId, DistributionId distributionId)
    {
        const DistributionId MaxDistributionId = 1000000;
        const RowId InitialRowId = 0;

        SCOPE_ASSERT(distributionId <= MaxDistributionId);

        const auto findIter = s_streamsToLastRowIds.find(streamId);

        // This is an exception condition since we're not supposed to be out of bounds.
        SCOPE_ASSERT(findIter != s_streamsToLastRowIds.end());

        auto& distributionIds = findIter->second;

        if (distributionId >= distributionIds.size())
        {
            distributionIds.resize(distributionId + 1, InitialRowId);
        }

        return ++distributionIds[distributionId];
    }

    RowId GetNextRowId(ScopeGuid streamId, VertexId vertexId)
    {
        return GetNextRowId(streamId.get(), (DistributionId) vertexId);
    }
}


// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

//namespace ScopeGeneratedClasses
//{
    // IDs representing UDTs to be used in native code
    enum UserDefinedTypeId
    {
        
    };

#if defined(COMPILE_MANAGED)
// Explicit instantiations for templated functions that are defined in managed code
#endif // defined(COMPILE_MANAGED)


    class PartitionSchema_GetSStream_0
    {
    public:
        FString m_Postcode;
        PartitionSchema_GetSStream_0();
        PartitionSchema_GetSStream_0(const PartitionSchema_GetSStream_0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        PartitionSchema_GetSStream_0(const PartitionSchema_GetSStream_0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static string GetDefinition()
        {
            return std::string{ u8"Postcode:string" };
        }

        static const bool containsUDT = false;

        UINT8 GetScopeCEPEventType() const { return 0; }
        ScopeDateTime GetScopeCEPEventStartTime() const { return ScopeDateTime::MinValue; }
        void SetScopeCEPEventStartTime(ScopeDateTime& startTime) {}
        void SetScopeCEPEventType(int type) {}
        bool IsScopeCEPCTI() const { return false; }
        void ResetScopeCEPStatus(ScopeDateTime startTime, ScopeDateTime endTime, int type) { }

        friend std::ostream& operator<<(std::ostream& os, const PartitionSchema_GetSStream_0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Postcode:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    class Process_3_Data0
    {
    public:
        FString m_Postcode1;
        Process_3_Data0();
        Process_3_Data0(const Process_3_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Process_3_Data0(const Process_3_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);



        static const bool containsUDT = false;

        UINT8 GetScopeCEPEventType() const { return 0; }
        ScopeDateTime GetScopeCEPEventStartTime() const { return ScopeDateTime::MinValue; }
        void SetScopeCEPEventStartTime(ScopeDateTime& startTime) {}
        void SetScopeCEPEventType(int type) {}
        bool IsScopeCEPCTI() const { return false; }
        void ResetScopeCEPStatus(ScopeDateTime startTime, ScopeDateTime endTime, int type) { }

        friend std::ostream& operator<<(std::ostream& os, const Process_3_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Postcode1:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

#if defined(COMPILE_MANAGED)

#endif // defined(COMPILE_MANAGED)


//}

// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<PartitionSchema_GetSStream_0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, PartitionSchema_GetSStream_0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Postcode);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Postcode);
                    }
                    else
                    {
                        row.m_Postcode.SetNull();
                    }
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
        static bool DeserializeKeyForSS(MemoryInputStream * input, PartitionSchema_GetSStream_0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Postcode);
                }
                else
                {
                    char ___masking___[1];
                    input->Read(___masking___[0]); 
                    if ((___masking___[0] & 1 ) != 1)
                    {
                        input->Read(row.m_Postcode);
                    }
                    else
                    {
                        row.m_Postcode.SetNull();
                    }
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
        static void DeserializeKey(ResourceInputStream * input, PartitionSchema_GetSStream_0 & row)
        {
            char type = 0, null = 0;
                input->Read(type);
                SCOPE_ASSERT(type != 34 && type != 35);
                input->Read(null);
                if (null)
                {
                    row.m_Postcode.SetNull();
                }
                else
                {
                    input->Read(row.m_Postcode);
                }
        }
        static void DeserializePartitionSpec(ResourceInputStream * input, PartitionSchema_GetSStream_0 & row)
        {
            char ___masking___[1];
            input->Read(___masking___); 
            if ((___masking___[0] & 1 ) != 1)
            {
                input->Read(row.m_Postcode);
            }
            else
            {
                row.m_Postcode.SetNull();
            }
        }

    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<PartitionSchema_GetSStream_0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, PartitionSchema_GetSStream_0 & row)
        {
            SIZE_T rowStart =  output->GetOutputer().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Postcode.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Postcode.IsNull())
            {
                output->Write(row.m_Postcode);
            }
            SIZE_T rowSize =  output->GetOutputer().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const PartitionSchema_GetSStream_0 & row)
        {
            SCOPE_ASSERT(false); 
        }
        static void SerializeKeyForSS(MemoryOutputStream* output, const PartitionSchema_GetSStream_0 & row)        
        {
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));

            bool hasNull = false;
            if (row.m_Postcode.IsNull())
            {
                hasNull = true;
                b = 1;
                ___masking___[0] |= 1;
            }
            output->Write(b);

            if (hasNull)
            {
                output->Write(___masking___, sizeof(___masking___));
            }
            if (!row.m_Postcode.IsNull())
            {
                output->Write(row.m_Postcode);
            }
        }
    };

// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Process_3_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Process_3_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Postcode1);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Postcode1);
                    }
                    else
                    {
                        row.m_Postcode1.SetNull();
                    }
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<Process_3_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Process_3_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputer().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Postcode1.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Postcode1.IsNull())
            {
                output->Write(row.m_Postcode1);
            }
            SIZE_T rowSize =  output->GetOutputer().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Process_3_Data0 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Process_3_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };

#pragma region Schema Constructors
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


    INLINE PartitionSchema_GetSStream_0::PartitionSchema_GetSStream_0()
    {
    }
    INLINE PartitionSchema_GetSStream_0::PartitionSchema_GetSStream_0(const PartitionSchema_GetSStream_0 & c, IncrementalAllocator * alloc) :
            m_Postcode(c.m_Postcode, alloc)
    {
    }

// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


    INLINE Process_3_Data0::Process_3_Data0()
    {
    }
    INLINE Process_3_Data0::Process_3_Data0(const Process_3_Data0 & c, IncrementalAllocator * alloc) :
            m_Postcode1(c.m_Postcode1, alloc)
    {
    }

#pragma endregion Schema Constructors
#pragma hdrstop
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_INIT_SHUTDOWN)
#if defined(COMPILE_MANAGED)
extern "C" __declspec(dllexport) void __stdcall InitVertexManaged(std::string * argv, int argc)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif
    cli::array<String^>^ arguments = ScopeEngineManaged::GroupArguments(argv, argc);
    ScopeEngineManaged::InitializeScopeEngineManaged(arguments);
}

extern "C" __declspec(dllexport) void __stdcall ShutdownVertexManaged(CLRMemoryStat& stat)
{
    ScopeEngineManaged::FinalizeScopeEngineManaged(stat);
}
#endif //#if defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
ScopeEngine::ScopeCEPCheckpointManager* g_scopeCEPCheckpointManager = NULL;

extern "C" __declspec(dllexport) void __stdcall InitVertexNative(VertexExecutionInfo * vertexExecutionInfo)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif

    ErrorManager::GetGlobal()->EnableJSON();
}

// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.



// Add broadcast vertex code
extern "C" __declspec(dllexport) void __stdcall SV_CopyThrough_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
{
    SCOPE_ASSERT(inputCnt == 1 && outputCnt == 1);
    IOManager::CopyStream(IOManager::GetGlobal()->GetDevice(inputs[0].inputFileName), IOManager::GetGlobal()->GetDevice(outputs[0].outputFileName));
}

#endif //#if defined(COMPILE_NATIVE)


#endif //#if defined(COMPILE_INIT_SHUTDOWN)
#pragma region SV1_Extract
#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

#if defined(COMPILE_NATIVE)
    template<> 
    class SStreamV3ExtractPolicy<PartitionSchema_GetSStream_0, UID_GetSStream_0, NullSchema>
    {
    public:
        typedef NullSchema CorrelatedParameters;
        typedef bool (*PredFn)(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, CorrelatedParameters* params);

    public:
        typedef PartitionSchema_GetSStream_0 DataRowSchema;
        typedef PartitionSchema_GetSStream_0 PartitionSchema;
        typedef PartitionSchema_GetSStream_0 DataKeySchema;
        typedef RowComparePolicy<DataKeySchema, DataKeySchema, UID_GetSStream_0> DataKeyComparePolicy;
        typedef ResourceInputStream SystemResourceInputStream;

        static const PartitioningType m_partitioning = HashPartition;
        static const bool m_residualFilterForKeyRange = false;
        static const bool m_residualFilterForRefinedHash = false;
        static const int  m_numberOfPartitionAfterRefinedHash = 0;
        static const bool m_keyRangeSeek = false;
        static const bool m_truncatedRangeKey = false;
        static const bool m_generateMetadata = false;
        static const UINT m_numOfBuffers = 4;
        static const bool m_hasCorrelatedSchema = false;

        // FailFastSStreamRead ignores the maxUnavailability value and forces a fast failure in case of store errors
        static const bool m_skipUnavailable = true/*0*/;

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>Postcode</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>DistrictCode</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Latitude</Name>\r\n      <Type>float</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Longitude</Name>\r\n      <Type>float</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static BYTE* DataColumnSizes()
        {
            static BYTE sizes[] = 
            {
                0,
                0,
                4,
                4,
            };

            return sizes;
        }
        static const UINT m_dataColumnSizesCnt = 4;

        static BYTE* IndexColumnSizes()
        {
            static BYTE sizes[] = 
                {
                // Low key
                0,
                // Hi Key
                0,
                8, // BlockOffset
                8, // BlockLength
                4, // RowCount
                };

            return sizes;
        }
        static const UINT m_indexColumnSizesCnt = 2 * 1 + 3;

        static UINT* SortKeys()
        {
            static UINT keys[] = 
                {
                0,
                };
            return keys;
        }
        static const UINT m_sortKeysCnt = 1;

        static const bool m_descending = false;


        static bool Deserialize(SSLibV3::ColumnIterator* iters, DataRowSchema & row, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT32 defaultDistributionId, UINT64 defaultRowId)
        {
            SCOPE_ASSERT(iters[0].HasData(blockEnd));
            if (iters[0].IsNull())
            {
                row.m_Postcode.SetNull();
            }
            else
            {
                row.m_Postcode.CopyFromNotNull((FString::PointerType)iters[0].DataRaw(), (int)iters[0].Length(), alloc);
            }
            return true;
        }

        static void SkipRow(SSLibV3::ColumnIterator* iters)
        {
            if (iters[0].IsNull())
            {
                iters[0].IncrementNull();
            }
            else
            {
                iters[0].IncrementVariable();
            }
            //// Section of the Partition Key iterators skip.
            //// Section of the System column iterators skip.
        }

        static PredFn* PredicatesLow() { return nullptr; }
        static PredFn* PredicatesHi() { return nullptr; }
        static const UINT m_predicateCnt = 0;
        static bool LowIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        // PredicateRefinedHashResidual
        static bool PredicateRefinedHashResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, int partitionIndex, int numberOfPartitions)
        {
            return true;
 
        }
    };


#endif // defined(COMPILE_NATIVE)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


    template<> 
    class KeyComparePolicy<PartitionSchema_GetSStream_0,UID_Process_1>
    {
    public:
        struct KeyStruct
        {
            FString m_Postcode;

            KeyStruct(PartitionSchema_GetSStream_0 & c) :
                m_Postcode(c.m_Postcode)
            {
            }

            KeyStruct(const PartitionSchema_GetSStream_0 & c, IncrementalAllocator * alloc) :
                m_Postcode(const_cast<PartitionSchema_GetSStream_0&>(c).m_Postcode, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Postcode(c.m_Postcode)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Postcode(const_cast<KeyStruct&>(c).m_Postcode, alloc)
            {
            }

            KeyStruct() :
                m_Postcode()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Postcode:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(PartitionSchema_GetSStream_0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Postcode, key.m_Postcode)) != 0)
                return r;
            return r;
        }

        static int Compare(PartitionSchema_GetSStream_0 * n1, PartitionSchema_GetSStream_0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Postcode, (*n2).m_Postcode)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(PartitionSchema_GetSStream_0 * p, int depth)
        {
            if (depth < 1 && (*p).m_Postcode.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Postcode.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Postcode.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Postcode.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Postcode.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(PartitionSchema_GetSStream_0 * p, int depth)
        {
            depth -= (int) ((*p).m_Postcode.size() + 1);
            if (depth < 0)
                return false;
            return true;
        }
    };


// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_NATIVE)
    typedef SStreamExtractor<PartitionSchema_GetSStream_0, SStreamV3ExtractPolicy<PartitionSchema_GetSStream_0, UID_GetSStream_0, NullSchema>, UID_GetSStream_0, NullSchema, false> SStreamV3ExtractorType_SV1_Extract_GetSStream_0;
    SStreamV3ExtractorType_SV1_Extract_GetSStream_0 * CreateExtractor_SV1_Extract_GetSStream_0(unique_ptr<SStreamV3ExtractorType_SV1_Extract_GetSStream_0> * extractor_ptr)
    {
        extractor_ptr->reset(new SStreamV3ExtractorType_SV1_Extract_GetSStream_0(0, "", UID_GetSStream_0));
        return extractor_ptr->get();
    }
#endif // defined(COMPILE_NATIVE)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV1_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        // check CPUID to make sure this machine supports SSE4_2 instructions
        // - this is incase we download a cluster vertex and try and debug it on a machine that doesn't support these instructions
        int cpuInfo[4];
        __cpuid(cpuInfo, 0x00000001);
        //Array index | Bit range | Description 
        // 2          | 20        | SSE4.2 extensions
        if ((cpuInfo[2] & (1 << 20)) == 0)
        {
            throw RuntimeException(E_USER_ERROR, "Please recompile __ScopeCodeGenEngine__.dll without /DUSE_SSE4_2");
            return;
        }
#endif

        Configuration::Create(ET_Azure, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        const bool IsNativeOnlyVertex = true;
        unique_ptr<SStreamV3ExtractorType_SV1_Extract_GetSStream_0> extractor_0_ptr;
        SStreamV3ExtractorType_SV1_Extract_GetSStream_0 * extractor_0 = CreateExtractor_SV1_Extract_GetSStream_0(&extractor_0_ptr);
        ULONG extractor_0_count = 1;

        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<PartitionSchema_GetSStream_0>> delegate_extractor_0_ptr (new OperatorDelegate<PartitionSchema_GetSStream_0>(OperatorDelegate<PartitionSchema_GetSStream_0>::FromOperator(extractor_0)));
        OperatorDelegate<PartitionSchema_GetSStream_0> * delegate_extractor_0 = delegate_extractor_0_ptr.get();
        ULONG delegate_extractor_0_count = 1;
        // Define sorter type
        typedef Sorter<PartitionSchema_GetSStream_0> SorterType_Process_1;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_1> sorter_Process_1_ptr (new SorterType_Process_1(delegate_extractor_0, &MKQSort<PartitionSchema_GetSStream_0>::Sort<KeyComparePolicy<PartitionSchema_GetSStream_0, UID_Process_1>, (sizeof(PartitionSchema_GetSStream_0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<PartitionSchema_GetSStream_0>::CreateDelegate<UID_Process_1>(), false, 5846859776 /*memoryQuota*/, UID_Process_1));
        SorterType_Process_1 * sorter_Process_1 = sorter_Process_1_ptr.get();
        ULONG sorter_Process_1_count = 1;
        // Define outputer type
        typedef Outputer<SorterType_Process_1, PartitionSchema_GetSStream_0, BinaryOutputPolicy<PartitionSchema_GetSStream_0>, BinaryOutputStream, false> OutputerType1_SV1_Extract;
        // Construct operator and initialize it
        unique_ptr<OutputerType1_SV1_Extract> outputer_SV1_Extract_out0_ptr(new OutputerType1_SV1_Extract(sorter_Process_1, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, UID_SV1_Extract_out0));
        OutputerType1_SV1_Extract * outputer_SV1_Extract_out0 = outputer_SV1_Extract_out0_ptr.get();
        try
        {
            // Init operator chain
            outputer_SV1_Extract_out0->Init();

            // Execute the whole vertex by calling the GetNextRow on top operator
            PartitionSchema_GetSStream_0 row;
            outputer_SV1_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputer_SV1_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            if (vertexExecutionInfo->m_reportStatusFunc != NULL)
            {
                ErrorManager::GetGlobal()->SetError(std::current_exception(), "VertexExecute");
                vertexExecutionInfo->m_reportStatusFunc(vertexExecutionInfo->m_statusReportContext);
            }
            
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        // Write out execution stats
        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputer_SV1_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV1_Extract
#pragma region SV2_Extract
#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

#if defined(COMPILE_NATIVE)
    template<> 
    class SStreamV3ExtractPolicy<PartitionSchema_GetSStream_0, UID_GetSStream_2, NullSchema>
    {
    public:
        typedef NullSchema CorrelatedParameters;
        typedef bool (*PredFn)(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, CorrelatedParameters* params);

    public:
        typedef PartitionSchema_GetSStream_0 DataRowSchema;
        typedef PartitionSchema_GetSStream_0 PartitionSchema;
        typedef PartitionSchema_GetSStream_0 DataKeySchema;
        typedef RowComparePolicy<DataKeySchema, DataKeySchema, UID_GetSStream_2> DataKeyComparePolicy;
        typedef ResourceInputStream SystemResourceInputStream;

        static const PartitioningType m_partitioning = HashPartition;
        static const bool m_residualFilterForKeyRange = false;
        static const bool m_residualFilterForRefinedHash = false;
        static const int  m_numberOfPartitionAfterRefinedHash = 0;
        static const bool m_keyRangeSeek = false;
        static const bool m_truncatedRangeKey = false;
        static const bool m_generateMetadata = false;
        static const UINT m_numOfBuffers = 4;
        static const bool m_hasCorrelatedSchema = false;

        // FailFastSStreamRead ignores the maxUnavailability value and forces a fast failure in case of store errors
        static const bool m_skipUnavailable = true/*0*/;

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>Postcode</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Total</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Males</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Females</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>OccupiedHouseholds</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static BYTE* DataColumnSizes()
        {
            static BYTE sizes[] = 
            {
                0,
                4,
                4,
                4,
                4,
            };

            return sizes;
        }
        static const UINT m_dataColumnSizesCnt = 5;

        static BYTE* IndexColumnSizes()
        {
            static BYTE sizes[] = 
                {
                // Low key
                0,
                // Hi Key
                0,
                8, // BlockOffset
                8, // BlockLength
                4, // RowCount
                };

            return sizes;
        }
        static const UINT m_indexColumnSizesCnt = 2 * 1 + 3;

        static UINT* SortKeys()
        {
            static UINT keys[] = 
                {
                0,
                };
            return keys;
        }
        static const UINT m_sortKeysCnt = 1;

        static const bool m_descending = false;


        static bool Deserialize(SSLibV3::ColumnIterator* iters, DataRowSchema & row, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT32 defaultDistributionId, UINT64 defaultRowId)
        {
            SCOPE_ASSERT(iters[0].HasData(blockEnd));
            if (iters[0].IsNull())
            {
                row.m_Postcode.SetNull();
            }
            else
            {
                row.m_Postcode.CopyFromNotNull((FString::PointerType)iters[0].DataRaw(), (int)iters[0].Length(), alloc);
            }
            return true;
        }

        static void SkipRow(SSLibV3::ColumnIterator* iters)
        {
            if (iters[0].IsNull())
            {
                iters[0].IncrementNull();
            }
            else
            {
                iters[0].IncrementVariable();
            }
            //// Section of the Partition Key iterators skip.
            //// Section of the System column iterators skip.
        }

        static PredFn* PredicatesLow() { return nullptr; }
        static PredFn* PredicatesHi() { return nullptr; }
        static const UINT m_predicateCnt = 0;
        static bool LowIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        // PredicateRefinedHashResidual
        static bool PredicateRefinedHashResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, int partitionIndex, int numberOfPartitions)
        {
            return true;
 
        }
    };


#endif // defined(COMPILE_NATIVE)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


    template<> 
    class KeyComparePolicy<Process_3_Data0,UID_Process_4>
    {
    public:
        struct KeyStruct
        {
            FString m_Postcode1;

            KeyStruct(Process_3_Data0 & c) :
                m_Postcode1(c.m_Postcode1)
            {
            }

            KeyStruct(const Process_3_Data0 & c, IncrementalAllocator * alloc) :
                m_Postcode1(const_cast<Process_3_Data0&>(c).m_Postcode1, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Postcode1(c.m_Postcode1)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Postcode1(const_cast<KeyStruct&>(c).m_Postcode1, alloc)
            {
            }

            KeyStruct() :
                m_Postcode1()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Postcode1:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Process_3_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Postcode1, key.m_Postcode1)) != 0)
                return r;
            return r;
        }

        static int Compare(Process_3_Data0 * n1, Process_3_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Postcode1, (*n2).m_Postcode1)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Process_3_Data0 * p, int depth)
        {
            if (depth < 1 && (*p).m_Postcode1.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Postcode1.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Postcode1.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Postcode1.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Postcode1.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Process_3_Data0 * p, int depth)
        {
            depth -= (int) ((*p).m_Postcode1.size() + 1);
            if (depth < 0)
                return false;
            return true;
        }
    };


// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

    static const char * StringTable_Process_3 [] =
    {
        "Postcode",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<PartitionSchema_GetSStream_0, Process_3_Data0, UID_Process_3>
    {
    public:

        static bool FilterTransformRow(PartitionSchema_GetSStream_0 & input, Process_3_Data0 & output, IncrementalAllocator * alloc)
        {

            int exceptionIndex = 0;
            try
            {
                    output.m_Postcode1 = input.m_Postcode;
                    exceptionIndex++;
                    return true;
                    }
                    catch(...)
                    {
                        std::throw_with_nested(RuntimeExpressionException(StringTable_Process_3[exceptionIndex]));
                    }
    }

            #pragma warning(push)
            #pragma warning(disable: 4100) // 'alloc': unreferenced formal parameter
            static void InitializeStatics(IncrementalAllocator * alloc)
            {
            #pragma warning(pop)
            }
    
            // get operator resource requirements
            static OperatorRequirements GetOperatorRequirements()
            {
                return OperatorRequirements().AddMemoryInRows(1, 1);
            }
        };
    
    
// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_NATIVE)
    typedef SStreamExtractor<PartitionSchema_GetSStream_0, SStreamV3ExtractPolicy<PartitionSchema_GetSStream_0, UID_GetSStream_2, NullSchema>, UID_GetSStream_2, NullSchema, false> SStreamV3ExtractorType_SV2_Extract_GetSStream_2;
    SStreamV3ExtractorType_SV2_Extract_GetSStream_2 * CreateExtractor_SV2_Extract_GetSStream_2(unique_ptr<SStreamV3ExtractorType_SV2_Extract_GetSStream_2> * extractor_ptr)
    {
        extractor_ptr->reset(new SStreamV3ExtractorType_SV2_Extract_GetSStream_2(2, "", UID_GetSStream_2));
        return extractor_ptr->get();
    }
#endif // defined(COMPILE_NATIVE)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV2_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        // check CPUID to make sure this machine supports SSE4_2 instructions
        // - this is incase we download a cluster vertex and try and debug it on a machine that doesn't support these instructions
        int cpuInfo[4];
        __cpuid(cpuInfo, 0x00000001);
        //Array index | Bit range | Description 
        // 2          | 20        | SSE4.2 extensions
        if ((cpuInfo[2] & (1 << 20)) == 0)
        {
            throw RuntimeException(E_USER_ERROR, "Please recompile __ScopeCodeGenEngine__.dll without /DUSE_SSE4_2");
            return;
        }
#endif

        Configuration::Create(ET_Azure, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        const bool IsNativeOnlyVertex = true;
        unique_ptr<SStreamV3ExtractorType_SV2_Extract_GetSStream_2> extractor_0_ptr;
        SStreamV3ExtractorType_SV2_Extract_GetSStream_2 * extractor_0 = CreateExtractor_SV2_Extract_GetSStream_2(&extractor_0_ptr);
        ULONG extractor_0_count = 1;

        // Define the type of the operator
        typedef FilterTransformer<SStreamV3ExtractorType_SV2_Extract_GetSStream_2, PartitionSchema_GetSStream_0, Process_3_Data0, UID_Process_3> FilterTransformerType_Process_3;
        // Construct operator and initialize it.
        unique_ptr<FilterTransformerType_Process_3> filterTransformer_Process_3_ptr (new FilterTransformerType_Process_3(extractor_0, UID_Process_3));
        FilterTransformerType_Process_3 * filterTransformer_Process_3 = filterTransformer_Process_3_ptr.get();
        ULONG filterTransformer_Process_3_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<Process_3_Data0>> delegate_filterTransformer_Process_3_ptr (new OperatorDelegate<Process_3_Data0>(OperatorDelegate<Process_3_Data0>::FromOperator(filterTransformer_Process_3)));
        OperatorDelegate<Process_3_Data0> * delegate_filterTransformer_Process_3 = delegate_filterTransformer_Process_3_ptr.get();
        ULONG delegate_filterTransformer_Process_3_count = 1;
        // Define sorter type
        typedef Sorter<Process_3_Data0> SorterType_Process_4;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_4> sorter_Process_4_ptr (new SorterType_Process_4(delegate_filterTransformer_Process_3, &MKQSort<Process_3_Data0>::Sort<KeyComparePolicy<Process_3_Data0, UID_Process_4>, (sizeof(Process_3_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Process_3_Data0>::CreateDelegate<UID_Process_4>(), false, 5842665472 /*memoryQuota*/, UID_Process_4));
        SorterType_Process_4 * sorter_Process_4 = sorter_Process_4_ptr.get();
        ULONG sorter_Process_4_count = 1;
        // Define outputer type
        typedef Outputer<SorterType_Process_4, Process_3_Data0, BinaryOutputPolicy<Process_3_Data0>, BinaryOutputStream, false> OutputerType1_SV2_Extract;
        // Construct operator and initialize it
        unique_ptr<OutputerType1_SV2_Extract> outputer_SV2_Extract_out0_ptr(new OutputerType1_SV2_Extract(sorter_Process_4, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, UID_SV2_Extract_out0));
        OutputerType1_SV2_Extract * outputer_SV2_Extract_out0 = outputer_SV2_Extract_out0_ptr.get();
        try
        {
            // Init operator chain
            outputer_SV2_Extract_out0->Init();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_3_Data0 row;
            outputer_SV2_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputer_SV2_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            if (vertexExecutionInfo->m_reportStatusFunc != NULL)
            {
                ErrorManager::GetGlobal()->SetError(std::current_exception(), "VertexExecute");
                vertexExecutionInfo->m_reportStatusFunc(vertexExecutionInfo->m_statusReportContext);
            }
            
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        // Write out execution stats
        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputer_SV2_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV2_Extract
#pragma region SV3_Combine
#if defined(COMPILE_SV3_COMBINE) || defined(COMPILE_ALL_VERTICES)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


    template<> 
    class KeyComparePolicy<PartitionSchema_GetSStream_0,UID_Join_5_0>
    {
    public:
        struct KeyStruct
        {
            FString m_Postcode;

            KeyStruct(PartitionSchema_GetSStream_0 & c) :
                m_Postcode(c.m_Postcode)
            {
            }

            KeyStruct(const PartitionSchema_GetSStream_0 & c, IncrementalAllocator * alloc) :
                m_Postcode(const_cast<PartitionSchema_GetSStream_0&>(c).m_Postcode, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Postcode(c.m_Postcode)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Postcode(const_cast<KeyStruct&>(c).m_Postcode, alloc)
            {
            }

            KeyStruct() :
                m_Postcode()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Postcode:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(PartitionSchema_GetSStream_0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Postcode, key.m_Postcode)) != 0)
                return r;
            return r;
        }

        static int Compare(PartitionSchema_GetSStream_0 * n1, PartitionSchema_GetSStream_0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Postcode, (*n2).m_Postcode)) != 0)
                return r;
            return r;
        }

    };


// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


    template<> 
    class KeyComparePolicy<Process_3_Data0,UID_Join_5_1>
    {
    public:
        struct KeyStruct
        {
            FString m_Postcode1;

            KeyStruct(Process_3_Data0 & c) :
                m_Postcode1(c.m_Postcode1)
            {
            }

            KeyStruct(const Process_3_Data0 & c, IncrementalAllocator * alloc) :
                m_Postcode1(const_cast<Process_3_Data0&>(c).m_Postcode1, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Postcode1(c.m_Postcode1)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Postcode1(const_cast<KeyStruct&>(c).m_Postcode1, alloc)
            {
            }

            KeyStruct() :
                m_Postcode1()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Postcode1:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Process_3_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Postcode1, key.m_Postcode1)) != 0)
                return r;
            return r;
        }

        static int Compare(Process_3_Data0 * n1, Process_3_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Postcode1, (*n2).m_Postcode1)) != 0)
                return r;
            return r;
        }

    };


// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_NATIVE)
    template<> 
    class CombinerPolicy<UID_Join_5> 
    {
    public:
        typedef KeyComparePolicy<PartitionSchema_GetSStream_0,UID_Join_5_0> LeftKeyPolicy;
        typedef KeyComparePolicy<Process_3_Data0,UID_Join_5_1> RightKeyPolicy;

        static const unsigned MaxPerKeyCrossSizeLimit = 0;

        static LONGLONG JoinerMemQuota()
        {
            return 0ULL;
        }

        // compare key from left and right schema object
        static int Compare(const PartitionSchema_GetSStream_0 * left, const Process_3_Data0 * right)
        {
            int r = 0;
            PartitionSchema_GetSStream_0 * n1 = const_cast<PartitionSchema_GetSStream_0 *>(left);
            Process_3_Data0 * n2 = const_cast<Process_3_Data0 *>(right);

            if ((r = ScopeTypeCompare((*n1).m_Postcode, (*n2).m_Postcode1)) != 0)
                return r;
            
            // Everything matches
            return 0;
        }

        static void CopyRow(PartitionSchema_GetSStream_0 * left, Process_3_Data0 * right, PartitionSchema_GetSStream_0 * out)
        {
                (*out).m_Postcode = (*left).m_Postcode;
        }

        static void CopyLeftRow(PartitionSchema_GetSStream_0 * left, PartitionSchema_GetSStream_0 * out)
        {
            (*out).m_Postcode = (*left).m_Postcode;
        }

        static void NullifyRightSide(PartitionSchema_GetSStream_0 * out)
        {
        }

        static void CopyRightRow(Process_3_Data0 * right, PartitionSchema_GetSStream_0 * out)
        {
        }

        static void NullifyLeftSide(PartitionSchema_GetSStream_0 * out)
        {
            (*out).m_Postcode.SetNull();
        }
    };
#endif // defined(COMPILE_NATIVE)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.



// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.

    template<> 
    class TextOutputPolicy<PartitionSchema_GetSStream_0, UID_SV3_Combine_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, false, true, false, true, UTF8, true, CharFormat_uint16>, CosmosOutput> * output, PartitionSchema_GetSStream_0 & row)
        {
            if (!row.m_Postcode.IsNull())
            {
                output->Write<FString,true>(row.m_Postcode);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, false, true, false, true, UTF8, true, CharFormat_uint16>, CosmosOutput> * output)
        {
            output->Write<string,true>(FString("Postcode", 8));
            output->WriteNewLine();
        }
    };

// All of the templates will throw a CS1591 warning because we
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
// All of the templates will throw a CS1591 warning because we 
// have /doc turned on in the CSharp compiler.
// The only way to solve this is to move all of the templates to their own
// project, and then turn off /doc.



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV3_Combine_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        // check CPUID to make sure this machine supports SSE4_2 instructions
        // - this is incase we download a cluster vertex and try and debug it on a machine that doesn't support these instructions
        int cpuInfo[4];
        __cpuid(cpuInfo, 0x00000001);
        //Array index | Bit range | Description 
        // 2          | 20        | SSE4.2 extensions
        if ((cpuInfo[2] & (1 << 20)) == 0)
        {
            throw RuntimeException(E_USER_ERROR, "Please recompile __ScopeCodeGenEngine__.dll without /DUSE_SSE4_2");
            return;
        }
#endif

        Configuration::Create(ET_Azure, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        const bool IsNativeOnlyVertex = true;
        // Define extractor type and construct object
        typedef Extractor<PartitionSchema_GetSStream_0, BinaryExtractPolicy<PartitionSchema_GetSStream_0>, BinaryInputStream> ExtractorType1_SV3_Combine;        
        unique_ptr<ExtractorType1_SV3_Combine> extractor_0_ptr= make_unique<ExtractorType1_SV3_Combine>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV1_Extract_out0);
        ExtractorType1_SV3_Combine * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Define extractor type and construct object
        typedef Extractor<Process_3_Data0, BinaryExtractPolicy<Process_3_Data0>, BinaryInputStream> ExtractorType2_SV3_Combine;        
        unique_ptr<ExtractorType2_SV3_Combine> extractor_1_ptr= make_unique<ExtractorType2_SV3_Combine>(inputs[1], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV2_Extract_out0);
        ExtractorType2_SV3_Combine * extractor_1 = extractor_1_ptr.get();
        ULONG extractor_1_count = 1;

        // Define the combiner operator
        typedef NativeCombinerWrapper<ExtractorType1_SV3_Combine, PartitionSchema_GetSStream_0, ExtractorType2_SV3_Combine, Process_3_Data0, PartitionSchema_GetSStream_0, LeftAntiSemiJoiner, UID_Join_5> CombinerType_Join_5;
        unique_ptr<CombinerType_Join_5> combiner_Join_5_ptr;
        combiner_Join_5_ptr.reset(new CombinerType_Join_5(extractor_0, extractor_1, UID_Join_5, 0, false, nullptr));
 
        CombinerType_Join_5 * combiner_Join_5 = combiner_Join_5_ptr.get();
        ULONG combiner_Join_5_count = 1;
        // Define outputer type
        typedef Outputer<CombinerType_Join_5, PartitionSchema_GetSStream_0, TextOutputPolicy<PartitionSchema_GetSStream_0, UID_SV3_Combine_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, false, true, false, true, UTF8, true, CharFormat_uint16>, CosmosOutput>, false> OutputerType3_SV3_Combine;
        // Construct operator and initialize it
        unique_ptr<OutputerType3_SV3_Combine> outputer_SV3_Combine_out0_ptr(new OutputerType3_SV3_Combine(combiner_Join_5, outputs[0].outputFileName, outputs[0].isFirstOutputPiece, x_outputBufSize, x_outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, false, true, false, "O", UTF8, true, CharFormat_uint16), UID_SV3_Combine_out0));
        OutputerType3_SV3_Combine * outputer_SV3_Combine_out0 = outputer_SV3_Combine_out0_ptr.get();
        try
        {
            // Init operator chain
            outputer_SV3_Combine_out0->Init();

            // Execute the whole vertex by calling the GetNextRow on top operator
            PartitionSchema_GetSStream_0 row;
            outputer_SV3_Combine_out0->GetNextRow(row);

            // Close operator chain
            outputer_SV3_Combine_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            if (vertexExecutionInfo->m_reportStatusFunc != NULL)
            {
                ErrorManager::GetGlobal()->SetError(std::current_exception(), "VertexExecute");
                vertexExecutionInfo->m_reportStatusFunc(vertexExecutionInfo->m_statusReportContext);
            }
            
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        // Write out execution stats
        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputer_SV3_Combine_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV3_Combine
#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)
#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)



#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)





#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV3_COMBINE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV3_COMBINE) || defined(COMPILE_ALL_VERTICES)
// Empty footer
