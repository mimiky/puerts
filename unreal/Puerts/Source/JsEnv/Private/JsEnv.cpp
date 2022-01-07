/*
 * Tencent is pleased to support the open source community by making Puerts available.
 * Copyright (C) 2020 THL A29 Limited, a Tencent company.  All rights reserved.
 * Puerts is licensed under the BSD 3-Clause License, except for the third-party components listed in the file 'LICENSE' which may
 * be subject to their corresponding license terms. This file is subject to the terms and conditions defined in file 'LICENSE',
 * which is part of this source code package.
 */

#include "JsEnv.h"

#include "JsEnvImpl.h"

namespace puerts
{
FJsEnv::FJsEnv(const FString& ScriptRoot)
{
    GameScript = std::make_unique<FJsEnvImpl>(ScriptRoot);
}

FJsEnv::FJsEnv(std::shared_ptr<IJSModuleLoader> InModuleLoader, std::shared_ptr<ILogger> InLogger, int InDebugPort,
    void* InExternalRuntime, void* InExternalContext)
{
    GameScript =
        std::make_unique<FJsEnvImpl>(std::move(InModuleLoader), InLogger, InDebugPort, InExternalRuntime, InExternalContext);
}

void FJsEnv::Start(const FString& ModuleName, const TArray<TPair<FString, UObject*>>& Arguments)
{
    GameScript->Start(ModuleName, Arguments);
}

void FJsEnv::LowMemoryNotification()
{
    GameScript->LowMemoryNotification();
}

void FJsEnv::WaitDebugger(double timeout)
{
    GameScript->WaitDebugger(timeout);
}

void FJsEnv::TryBindJs(const class UObjectBase* InObject)
{
    GameScript->TryBindJs(InObject);
}

void FJsEnv::RebindJs()
{
    GameScript->RebindJs();
}

FString FJsEnv::CurrentStackTrace()
{
    return GameScript->CurrentStackTrace();
}

void FJsEnv::InitExtensionMethodsMap()
{
    GameScript->InitExtensionMethodsMap();
}

void FJsEnv::ReloadModule(FName ModuleName, const FString& JsSource)
{
    GameScript->ReloadModule(ModuleName, JsSource);
}

}    // namespace puerts
