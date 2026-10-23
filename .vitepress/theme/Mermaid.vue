<script setup>
import { ref, onMounted, watch } from 'vue';
import { useData } from 'vitepress';

const props = defineProps({ code: String });
const { isDark } = useData();
const svg = ref('');
const id = `mermaid-${Math.random().toString(36).slice(2)}`;

// mermaid is loaded on demand, only on pages that carry a diagram
const render = async () => {
  const { default: mermaid } = await import('mermaid');
  mermaid.initialize({ startOnLoad: false, theme: isDark.value ? 'dark' : 'default' });
  ({ svg: svg.value } = await mermaid.render(id, decodeURIComponent(props.code)));
};

onMounted(render);
watch(isDark, render);
</script>

<template>
  <div class="mermaid" v-html="svg" />
</template>
