# Teacher Guide Style

Writing-style conventions for MeshMass kit teacher's guides. Established through the **Mini Tank Starter Kit** (`docs/MeshMass-Mini-Tank-Starter-Kit.md` and its `docs/zh/` counterpart), which now serves as the worked reference. New kit docs (and future sessions of existing kit docs) should follow this style.

## Audience and voice

- Teacher-facing throughout. Describe concepts the teacher will paraphrase; do not put words in their mouth.
- Direct address ("Tour it by following its parts"), active voice, plain register.
- **No scripted teacher dialog, no predicted student responses, no "students will say X / wait for Y" stage directions.**

## Structural conventions

- Two-level hierarchy: **Session** (`##`) → **Step** (`###`) → arc dividers or assembly sub-steps (`####`).
- **Narrative-beat arc dividers** (e.g. `#### Meet the Parts`, `#### Make the Motor Spin`) when a Step covers multiple conceptual beats.
- **Numbered sub-steps** (`#### 4.1`, `#### 4.2`, ...) for assembly procedures with multiple sequential operations.
- Assembly steps follow a strict shape: **Materials** / **Tool** / **Instructions** (numbered list).
- The right-side outline shows up to H4 (`outline: [2, 4]` in `.vitepress/config.js`).

## Container conventions

- `::: info Experiment #N: …` — every hands-on experiment is boxed and numbered sequentially across the whole doc.
- `::: warning` for important operational notes (e.g. *No Power Switch*).
- `::: danger` for genuine safety rules.
- `> **💡 Tip for Teachers:**` blockquotes for optional teacher enrichment — never load-bearing for the lesson.
- Short plain **"divider sentences"** between experiments (outside the box) — motivate the next experiment in 1–2 sentences.

## Pedagogical flow

- **Concrete experience first, abstraction second:** experiment first, then name the concept.
- Concepts arrive in dependency order, each tied back to what students just observed.
- New STEM terms **bolded on first introduction**, in context (*circuit*, *switch*, *voltage*, *PWM*, *MCU*).
- Forward-promises woven in ("…that is what Session 2 covers", "we meet next").
- Optional historical / design-tradeoff enrichment lives in **teacher tips**, not the main flow.
- **No minute-by-minute timing** within missions / experiments. Session-level duration (e.g. "Session 1: Get Running First! (3 Hours)") is OK.

## Tone

- Short paragraphs. No padding. Plain English.
- Analogies anchored in **physical intuition** (water tower → terminals, water pressure → voltage, bicycle gear → gearbox, square snake → antenna).
- Use ` - ` (space-hyphen-space) instead of em-dashes consistently.
- No emoji decoration except the standard ⚠️ / 💡 indicators inside warnings and tips.
- Section/experiment titles are **utilitarian, not playful** (*Prove All the Electronics Work*, not *Bring It All Together*).

## Cross-doc

- Technical part names stay in English even in the Chinese version (RX4M4S, TX6A4D, DM0, DM1, PB2×5).
- Section headings translate; brand/SKU/connector names don't.
- Internal links in Chinese pages point to `/zh/…` versions of related docs.

## Localisation framing

- **English version** targets a native-English teacher → ~10yo students with ~2 years of English. STEM English is the vocabulary gap, not everyday English.
- **Chinese version** targets a native-Chinese teacher → ~10yo Chinese students in their native language. Drop the ESL framing; structure and pedagogy stay the same.

## How to apply

- For new kit docs, start from the Mini Tank structure: **Author → Overview (teacher-guide intro) → At a Glance (preview) → Sessions (active lesson) → Summary → reference sections** (Learning Path, About the Kit, BOM, Beyond This Kit, Discussion, Related Products).
- When unsure about a stylistic choice, look at how the Mini Tank doc handles a similar moment — it is the worked example.
