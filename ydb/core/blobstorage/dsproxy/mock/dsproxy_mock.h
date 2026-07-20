#pragma once

#include "defs.h"
#include <ydb/core/base/blobstorage_common.h>
namespace NKikimr {

    namespace NFake {
        class TProxyDS;
    } // NFake

    IActor *CreateBlobStorageGroupProxyMockActor(TIntrusivePtr<NFake::TProxyDS> model);
    IActor *CreateBlobStorageGroupProxyMockActor(TGroupId groupId);

    struct TBSFailureInjectionConfig
    {
        double FailureProbability = 0.0;
        bool IncludeStaticGroups = false;
        std::optional<ui64> RandomSeed = 0;
    };
    IActor *CreateBlobStorageGroupFailureInjectingActor(TActorId actorId, TGroupId groupId, TBSFailureInjectionConfig config);

} // NKikimr
