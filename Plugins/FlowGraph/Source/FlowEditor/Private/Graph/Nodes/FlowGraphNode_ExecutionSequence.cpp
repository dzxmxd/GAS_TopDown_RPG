// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Graph/Nodes/FlowGraphNode_ExecutionSequence.h"
#include "Nodes/Route/FlowNode_ExecutionMultiGate.h"
#include "Nodes/Route/FlowNode_ExecutionSequence.h"

#include "Textures/SlateIcon.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowGraphNode_ExecutionSequence)

UFlowGraphNode_ExecutionSequence::UFlowGraphNode_ExecutionSequence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AssignedNodeClasses = {UFlowNode_ExecutionSequence::StaticClass(), UFlowNode_ExecutionMultiGate::StaticClass()};
}

FSlateIcon UFlowGraphNode_ExecutionSequence::GetIconAndTint(FLinearColor& OutColor) const
{
	static FSlateIcon Icon("FlowEditorStyle", "GraphEditor.Sequence_16x");
	return Icon;
}
